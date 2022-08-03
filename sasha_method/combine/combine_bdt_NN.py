import pandas as pd
import matplotlib.pyplot as plt
import math

# read data from hdf5
df = pd.read_hdf('../bdt/bdt.h5', key='data')
print(df)

df2 = pd.read_hdf('../split/result.h5', key='data')
print(df2)

# plot ROC curve

import sklearn.metrics as metrics
out = df['classID'].values
res = df['BDT'].values

out2 = df2['out'].values
res2 = df2['res2'].values

# make the right output
res *= -1;

fpr, tpr, threshold = metrics.roc_curve(out,res)
fpr2, tpr2, threshold2 = metrics.roc_curve(out2, res2)
# roc_auc = metrics.auc(fpr, tpr) # area under curve

plt.rc('font', size=16)

plt.figure("ROC")
plt.plot(fpr, tpr, color = 'b', label ='BDT')
plt.plot(fpr2, tpr2, color = 'g', label = 'NN')
plt.plot([0,1], [0,1], 'r--')
plt.xlim([0,1])
plt.ylim([0,1])
plt.xlabel('False Positive Rate')
plt.ylabel('True Positive Rate')
plt.legend()
plt.grid()
plt.subplots_adjust(bottom=0.15)
plt.savefig("ROC_compare.pdf")
