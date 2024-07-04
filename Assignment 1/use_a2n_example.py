#!/usr/bin/env python3
"""
Add a Shebang Line ("#!/usr/bin/env python3") to the top of your Python script.
By adding this line a the top of your program you can run your Python code in a Terminal using:

`./use_a2n_example.py`

Which is the same way as running an executable C code object file.
This tells the system to use Python to execute the script.
Adjust python3 to python if that's how Python is referred to on your system.

If we don't add this to the  top of .py file, then we have to run the code in a Terminal using:

`python3 use_a2n_example.py`

What ever works for you.

"""
# ----------------------------
# Python's ctypes library can be used to load and call the function from the shared library.
import ctypes

# ---------------------------
"""
Load the shared library
For Linux/Mac, use: my_lib = ctypes.CDLL('./liba2n.so')
For Windows, use: my_lib = ctypes.CDLL('./a2n.dll')
"""
my_lib = ctypes.CDLL('./liba2n.so')

# ---------------------------
# Define the argument and return types

my_lib.my_a2n.argtypes = (ctypes.c_int, ctypes.c_int)
my_lib.my_a2n.restype = ctypes.c_int

# ---------------------------
# This is 2^n function from scratch (not using any package)
def power_of_two(n):
    """
    Computes 2^n by multiplying 2 by itself n times.
    
    :param n: The exponent (must be a non-negative integer).
    :return: The result of 2^n.
    """
    # if n < 0:
    #     raise ValueError("The exponent must be a non-negative integer.")
    
    result = 1
    for _ in range(n):
        result *= 2
    
    return result


# Constants in a*2^n
a = 1
n = 50

# my_a2n() is our C code package
print(f"my_a2n({a}, {n}): {my_lib.my_a2n(a,n)}")

# pow() is a predefined function on python
print(f"{a} * pow(2,{n}): {a*pow(2, n)}")

# power_of_two() is developed from scratch in Python
print(f"{a} * 2^{n}     : {a*power_of_two(n)}")