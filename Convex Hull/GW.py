import numpy as np
import matplotlib.pyplot as plt
import random
BATCH_SIZE=20
points=np.array([[random.randint(0,100),random.randint(0,100)] for i in range(BATCH_SIZE)])


def sort_by_last(points):
    sorted=points[np.lexsort(points.T)]
    return sorted


points=sort_by_last(points)
alpha=\
    [
        np.arcsin((points[i]-points[0])[0]/np.sqrt(np.square(points[i]-points[0])[0]+np.square(points[i]-points[0])[1]))
        for i in range(1,BATCH_SIZE)
    ]
alpha=np.array([-5]+alpha)
points_alpha=np.c_[points,alpha]
points_alpha=sort_by_last(points_alpha)
points=points_alpha.T[0:2].T
def get_beta(vector1,vector2):
    beta=vector1.data[0]*vector2.data[1]-vector1.data[1]*vector2.data[0]
    return beta

edge_dots=points
has=1
while has!=0:
    has=0
    for i in range(len(edge_dots)):
        beta=get_beta(edge_dots[(i+1)%len(edge_dots)]-edge_dots[i%len(edge_dots)],
                      edge_dots[(i+2)%len(edge_dots)]-edge_dots[(i+1)%len(edge_dots)])
        if(beta>=0):
            has=1
            edge_dots=np.delete(edge_dots,(i+1)%len(edge_dots),axis=0)
            beta = get_beta(edge_dots[(i + 1) % len(edge_dots)] - edge_dots[i % len(edge_dots)],
                            edge_dots[(i + 2) % len(edge_dots)]-edge_dots[(i+1)%len(edge_dots)])
edge_dots=edge_dots.tolist()
edge_dots.append(edge_dots[0])
edge_dots=np.array(edge_dots)
plt.scatter(points.T[0],points.T[1])
plt.plot(edge_dots.T[0],edge_dots.T[1])
plt.show()