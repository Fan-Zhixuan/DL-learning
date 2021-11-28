import random
a=range(0,1050)
b=random.sample(a,105)
b = sorted(b)
with open("D:/github/PaddleSeg/dataset/val.txt","w") as f:
    for i in b:
        f.write('image_2000grain_3floor_1118/image'+str(i)+'.jpg label_2000grain_3floor_1118/label'+str(i)+'.png\n')
f.close
with open("D:/github/PaddleSeg/dataset/train.txt","w") as f:
    for i in a:
        if i not in b:
            f.write('image_2000grain_3floor_1118/image'+str(i)+'.jpg label_2000grain_3floor_1118/label'+str(i)+'.png\n')
f.close
# img_list = []
# with open("train_list.txt","r") as f:
#     for line in f.readlines():
#         img_list.append(line)
# f.close
# with open("val_list.txt","w") as f:
#     for line in img_list:
#         if random.random() < 0.1:
#             f.write(line)
# f.close