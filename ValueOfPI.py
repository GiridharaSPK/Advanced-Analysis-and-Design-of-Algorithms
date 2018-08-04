
# coding: utf-8

# In[1]:


import matplotlib.pyplot as plt
import random
import numpy
import pylab


# In[2]:


count=1
incount=1


# In[3]:


x = numpy.linspace(0,1,1000) # 100 linearly spaced numbers
y = numpy.sqrt(1-x**2)# computing the values of sin(x)/x
pylab.plot(x,y)


# In[4]:


while(count<100000000):
    x=random.uniform(0.0,1.0)
    y=random.uniform(0.0,1.0)
    if((x**2+y**2)<1):
        incount+=1
    if(count%10000000==0):
        print((incount*4.0)/count)
    if(count%1000000==0):
        plt.scatter(x,y)
    count+=1
pylab.show()
plt.show()


# In[5]:


print((incount*4.0)/count)

