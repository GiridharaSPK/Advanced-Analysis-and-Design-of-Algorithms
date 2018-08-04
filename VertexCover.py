from pulp import *

A= [[0,1,1,0,0,0,0],
    [1,0,1,1,0,0,0],
    [1,1,0,0,1,0,1],
    [0,1,0,0,0,1,0],
    [0,0,1,0,0,1,0],
    [0,0,0,1,1,0,1],
    [0,0,0,0,0,1,0]
    ]

prob = LpProblem("VertexCover",LpMinimize)


variables=[]
for i in range(len(A[0])):
    variables.append(LpVariable("A_{}".format(i),0,1))

for i in range(len(A[0])):
    prob+=lpSum(variables)

#constraints
for i in range(len(A[0])):
    for j in range(len(A[0])):
        if A[i][j]==1:
            prob+=variables[i]+variables[j]>=1

prob.writeLP("VertexCover.lp")

prob.solve()

print("Status:", LpStatus[prob.status])
for v in prob.variables():
    print(v.name," : ", v.varValue)
print("objective=", value(prob.objective))
