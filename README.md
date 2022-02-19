# ack
calculate Ackermann function step by step in C++

# Ackermann function
ack [a0] [a1] [a2] ... [ak] calculates A(a0,A(a1, ... A(ak-1, ak)))...) step by step until the value is calculated as a natural number.

A(x,y) is the Péter's Ackermann function [1]. Which can be represented as the followings:
- A(0  ,y  ) = y+1           (for all y)
- A(x+1,0  ) = A(x,1)        (for all x>0)
- A(x+1,y+1) = A(x,A(x+1,y)) (for all x>0 and y>0)

#References
- [1] Péter, R. Rekursive Funktionen in der Komputer-Theorie. Budapest: Akad. Kiado, 1951.
