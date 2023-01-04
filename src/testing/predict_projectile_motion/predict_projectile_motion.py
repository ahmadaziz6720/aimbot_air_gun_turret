import math

def predict_projectile_motion(x, y): 
    t = x / (v * math.cos(theta))
    
    v = (x / t) / math.cos(theta)
    
    theta = math.atan((y / x) + (g / (2 * v**2 * math.cos(theta)**2)))
    
    return v, theta

import math

def predict_trajectory(x, y, v, theta):
    t = x / (v * math.cos(theta))
    y_max = y + (v * t * math.sin(theta)) - (0.5 * g * t**2)
    x_max = x + (v * t * math.cos(theta))
    
    x_values = []
    y_values = []
    for t in range(0, 2 * t):
        x_values.append(v * t * math.cos(theta))
        y_values.append(y + (v * t * math.sin(theta)) - (0.5 * g * t**2))
    
    return x_values, y_values
