import time
from pySerialTransfer import pySerialTransfer as txfer

X1 = [0, 0]
# X2 = [1, 1, 1, 1, 1, .... , 1] ---> X1 and X2 are long array

try:
    link = txfer.SerialTransfer('COM6', 115200, debug=True)
    link.open()

    start = 0
    step = 10
    counter = 0

    while counter < len(X1):
        sendSize = 0

        X1_= X1[start:start+step] ---> I split it in order to get under 254 bytes per packet.
        X2_= X2[start:start+step]
        message = "notes"
        
        messageSize = link.tx_obj(message) 
        sendSize += messageSize

        X1Size = link.tx_obj(X1_, sendSize) - sendSize
        sendSize += X1Size

        X2Size = link.tx_obj(X2_, sendSize) - sendSize
        sendSize += X2Size

        link.send(sendSize, packet_id=0) ---> I recently tried to add packet_id information to don't messing up the receiving part.
        counter += len(X1_)

        #print('SENT: {} {} {}'.format(message, X1_, X2_))

        while not link.available():
            pass

        rec_message = link.rx_obj(obj_type=type(message), obj_byte_size=messageSize)
        rec_X1 = link.rx_obj(obj_type=type(X1_), obj_byte_size=X1Size, list_format='i', start_pos = messageSize)
        rec_X2 = link.rx_obj(obj_type=type(X2_), obj_byte_size=X2Size, list_format='i', start_pos = messageSize + X1Size)

        start += step
        print("Recu:\t{} - {} et {}".format(rec_message, rec_X1, rec_X2))


    while True:
        sendSize2 = 0
        message2 = "click"
        messageSize = link.tx_obj(message2)
        sendSize2 += messageSize

        print("Ready to click...")
        link.send(sendSize2, packet_id=0)
        #print('SENT: {}'.format(message2))

        while not link.available():
            pass

        rec_message = link.rx_obj(obj_type=type(message2), obj_byte_size=messageSize)
        print("Recu:\t{}".format(rec_message))

        raise KeyboardInterrupt

except KeyboardInterrupt:
    try:
        link.close()
    except:
        pass

except:
    import traceback
    traceback.print_exc()

    try:
        link.close()
    except:
        pass