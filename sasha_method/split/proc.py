import pandas as pd
import matplotlib.pyplot as plt

# read data from hdf5
df = pd.read_hdf('result.h5', key='data')
print(df)

# plot ROC curve

import sklearn.metrics as metrics
out = df['out'].values
res = df['res2'].values
fpr, tpr, threshold = metrics.roc_curve(out,res)
# roc_auc = metrics.auc(fpr, tpr) # area under curve

plt.rc('font', size=16)

plt.figure("ROC")
plt.plot(fpr, tpr, 'b')
plt.plot([0,1], [0,1], 'r--')
plt.xlim([0,1])
plt.ylim([0,1])
plt.xlabel('False Positive Rate')
plt.ylabel('True Positive Rate')
plt.grid()
plt.subplots_adjust(bottom=0.15)
plt.savefig("ROC.pdf")
