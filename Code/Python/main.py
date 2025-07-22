import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

def load_data(filename): # converts data into columns to be used for evaluation metrics.
    data = pd.read_csv(filename)
    columns = data.columns.tolist()
    data = [data[column].tolist() for column in columns]
    return data

def confusion_matrix(expected,actual):
    tp = 0
    tn = 0
    fp = 0
    fn = 0
    for i,j in zip(expected,actual): #compares expected and actual values
        if (i == 0 and i == j): # counts true negatives
            tn += 1
        elif (i == 1 and i == j): #counts true positives
            tp += 1
        elif (i == 0 and i != j): #counts false negatives
            fn += 1
        elif (i == 1 and i != j): #counts false positives
            fp += 1
    conf = np.array([[tp, fp], [fn,tn]])
    labels = ['Positive', 'Negative'] #the rest of the code below plots the confusion matrix
    fig, ax = plt.subplots()
    img = ax.imshow(conf, cmap = plt.cm.Blues) # generates graphic, colormap is blue (graphic will have darker and lighter shades of blue for classification)
    cbar = ax.figure.colorbar(img, ax=ax)
    ax.set(xticks = np.arange(conf.shape[1]), yticks = np.arange(conf.shape[0]),
           xticklabels = labels, yticklabels = labels,
           xlabel = "Expected", ylabel = "Actual") #labels for prediction and target
    plt.setp(ax.get_xticklabels(), rotation = 45, ha = "right", rotation_mode = "anchor") #adjusts x ticks for readability
    for i in range(conf.shape[0]):
        for j in range(conf.shape[1]):
            text = ax.text(j, i, conf[i,j], ha = "center", va = "center", color = "gray", fontsize = 15) #writes number of tp,tn,fp,fn on graphic
    plt.set_title = ("Confusion Matrix")
    plt.tight_layout() #encapsulates everything on plot (without this line of code you may not be able to see the axes titles)
    plt.show() #show plot

data = load_data('Data/ECE 16 Iteration 1 + 2 - Sheet1.csv')
first_iter_exp = data[0]
first_iter_act = data[1]
second_iter_exp = data[2]
second_iter_act = data[3]
final_iter_exp = data[6]
final_iter_act = data[7]
iter1_conf_matrix = confusion_matrix(first_iter_exp, first_iter_act)
iter2_conf_matrix = confusion_matrix(second_iter_exp, second_iter_act)
final_conf_matrix = confusion_matrix(final_iter_exp, final_iter_act)
