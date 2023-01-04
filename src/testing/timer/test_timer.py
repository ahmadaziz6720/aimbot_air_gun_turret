import time

start_time = time.time_ns()
print("something")
# time taken by this operation in milliseconds
print((time.time_ns() - start_time) / 1000000)
