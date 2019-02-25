# -*- coding: utf-8 -*-
"""
Created on Fri Feb  1 11:57:49 2019

@author: david
"""

import numpy as np

def inphaseQuadrature():
    # i = np.array([0.0, 1.0, 0.5, -0.5, -0.5])
    # q = np.array([0.0, 1.0, 0.25, 0.25, -0.75])
    i = np.random.uniform(-1, 1, 4)
    q = np.random.uniform(-1, 1, 4)
    iq = i + 1j*q
    print(iq)
    angle = np.arctan(q, i)
    print(angle*180/np.pi)
 
    r = np.sqrt(np.square(i) + np.square(q))
    print(r)