import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# read data from hdf5
df = pd.read_hdf('result.h5', key='data')
print(df)

# create histograms
df0 = df[df['out']==0]
df1 = df[df['out']==1]

vars = df.columns.values
vars = vars[vars!='out']

plt.rc('font', size=16)

for var in vars:
  print(var)
  res1_out0 = df0[var].values
  res1_out1 = df1[var].values
  plt.figure("fig_"+var) # or plt.figure(clear=True)
  # figure out the variable range
  xmin = 0
  xmax = 1
  if var[:2]=='dR':
    xmin = 0
    xmax = 5
  elif var[:1]=='m':
    xmin = 0
    xmax = 500
  # normalize histograms to 1: density=True
  plt.hist([res1_out0,res1_out1], np.linspace(xmin, xmax, 100), histtype='step',color=('red','blue'), label=['out=0','out=1'], density=True)
  plt.xlabel(var)
  plt.ylabel('Arbitrary units')
  plt.legend()
  plt.subplots_adjust(bottom=0.15)
  plt.savefig("var_"+var+".pdf")
