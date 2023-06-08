#!/usr/bin/env python
# coding: utf-8

# In[5]:


import matplotlib.pyplot as plt
import numpy as np


# In[22]:


x=np.array([0.33333,0.66667,1,1.33333,1.66667])
w=np.array([1.03293,1.06736,1.10349,1.14137,1.18083])
u=np.array([1.0339,1.06894,1.10517,1.14263,1.18136])
error=np.array([0.000968195,0.00157673,0.00167768,0.00126446,0.000530511])


# In[23]:


plt.figure(figsize=(10,5))
plt.plot(x,w,'*', color="red",label="Wij")
plt.plot(x,u,color='blue',label="u(x,y)")
plt.title("Wij & u(x,y)")
plt.legend()
plt.xlabel('x')
plt.savefig("ejemplo1.jpg")
plt.show()


# In[24]:


plt.figure(figsize=(10,5))
plt.plot(x,error,'*', color="black",label="|Wij-u(x,y)|")
#plt.plot(x,u,color='purple',label="u(x,y)")
plt.title("Error absoluto")
plt.legend()
plt.xlabel('x')
plt.ylabel('error')
plt.savefig("ejemplo1_error.jpg")
plt.show()


# In[ ]:




