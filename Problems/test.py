# from google.colab import drive
# drive.mount('/content/drive')
# import os

# # TODO: Fill in the Google Drive path where you uploaded the assignment
# '''Example: If you create a A3 folder and put all the files under A3 folder, then 'A3/A3'-->this would be the file path
# if you just extract the folderas it is and upload it on google drive'''
# # GOOGLE_DRIVE_PATH_AFTER_MYDRIVE = 'A3/A3'
# GOOGLE_DRIVE_PATH_AFTER_MYDRIVE =''       #enter your path here
# GOOGLE_DRIVE_PATH = os.path.join('drive', 'My Drive',GOOGLE_DRIVE_PATH_AFTER_MYDRIVE)
# print(os.listdir(GOOGLE_DRIVE_PATH))
# import sys
# sys.path.append(GOOGLE_DRIVE_PATH)
# import fetch
# import torch
# import torchvision
# import matplotlib.pyplot as plt
# import statistics

# plt.rcParams['figure.figsize'] = (10.0, 8.0)
# plt.rcParams['font.size'] = 16
# x_train, y_train, x_test, y_test = fetch.data.cifar10()

# print('Training set:', )
# print('  data shape:', x_train.shape)
# print('  labels shape: ', y_train.shape)
# print('Test set:')
# print('  data shape: ', x_test.shape)
# print('  labels shape', y_test.shape)
# import random
# from torchvision.utils import make_grid

# classes = ['plane', 'car', 'bird', 'cat', 'deer', 'dog', 'frog', 'horse', 'ship', 'truck']
# samples_per_class = 12
# samples = []
# for y, cls in enumerate(classes):
#     plt.text(-4, 34 * y + 18, cls, ha='right')
#     idxs, = (y_train == y).nonzero(as_tuple=True)
#     for i in range(samples_per_class):
#         idx = idxs[random.randrange(idxs.shape[0])].item()
#         samples.append(x_train[idx])
# img = torchvision.utils.make_grid(samples, nrow=samples_per_class)
# plt.imshow(fetch.tensor_to_image(img))
# plt.axis('off')
# plt.show()
# num_train = 500
# num_test = 250

# x_train, y_train, x_test, y_test = fetch.data.cifar10(num_train, num_test)

# print('Training set:', )
# print('  data shape:', x_train.shape)
# print('  labels shape: ', y_train.shape)
# print('Test set:')
# print('  data shape: ', x_test.shape)
# print('  labels shape', y_test.shape)
# def compute_distances_two_loops(x_train: torch.Tensor, x_test: torch.Tensor):
#     """
#     Computes the squared Euclidean distance between each element of training
#     set and each element of test set. Images should be flattened and treated
#     as vectors.

#     This implementation uses a naive set of nested loops over the training and
#     test data.

#     The input data may have any number of dimensions -- for example this
#     function should be able to compute nearest neighbor between vectors, in
#     which case the inputs will have shape (num_{train, test}, D); it should
#     also be able to compute nearest neighbors between images, where the inputs
#     will have shape (num_{train, test}, C, H, W). More generally, the inputs
#     will have shape (num_{train, test}, D1, D2, ..., Dn); you should flatten
#     each element of shape (D1, D2, ..., Dn) into a vector of shape
#     (D1 * D2 * ... * Dn) before computing distances.

#     The input tensors should not be modified.

#     Args:
#         x_train: Tensor of shape (num_train, D1, D2, ...)
#         x_test: Tensor of shape (num_test, D1, D2, ...)

#     Returns:
#         dists: Tensor of shape (num_train, num_test) where dists[i, j]
#             is the squared Euclidean distance between the i-th training point
#             and the j-th test point. It should have the same dtype as x_train.
#     """
#     # Initialize dists to be a tensor of shape (num_train, num_test) with the
#     # same datatype and device as x_train
#     num_train = x_train.shape[0]
#     num_test = x_test.shape[0]
#     dists = x_train.new_zeros(num_train, num_test)
#     ##########################################################################
#     # TODO: Implement this function using a pair of nested loops over the    #
#     # training data and the test data.
#     x_train_flat = x_train.view(num_train, -1)
#     x_test_flat = x_test.view(num_test, -1)

#     for i in range(num_train):
#         for j in range(num_test):
#             dists[i, j] = torch.sum((x_train_flat[i] - x_test_flat[j]) ** 2)

#     #YOURCODE

#     return dists

# dists = compute_distances_two_loops(x_train, x_test)
# print('dists has shape: ', dists.shape)
# print(dists)

# plt.imshow(dists.numpy(), cmap='gray', interpolation='none')
# plt.colorbar()
# plt.xlabel('test')
# plt.ylabel('train')
# plt.show()

# def compute_distances_no_loops(x_train: torch.Tensor, x_test: torch.Tensor):
#     """
#     Computes the squared Euclidean distance between each element of training
#     set and each element of test set. Images should be flattened and treated
#     as vectors.

#     This implementation should not use any Python loops. For memory-efficiency,
#     it also should not create any large intermediate tensors; in particular you
#     should not create any intermediate tensors with O(num_train * num_test)
#     elements.

#     Similar to `compute_distances_two_loops`, this should be able to handle
#     inputs with any number of dimensions. The inputs should not be modified.

#     Args:
#         x_train: Tensor of shape (num_train, C, H, W)
#         x_test: Tensor of shape (num_test, C, H, W)

#     Returns:
#         dists: Tensor of shape (num_train, num_test) where dists[i, j] is
#             the squared Euclidean distance between the i-th training point and
#             the j-th test point.
#     """
#     # Initialize dists to be a tensor of shape (num_train, num_test) with the
#     # same datatype and device as x_train
#     num_train = x_train.shape[0]
#     num_test = x_test.shape[0]
#     dists = x_train.new_zeros(num_train, num_test)
#     ##########################################################################
#     # TODO: Implement this function without using any explicit loops and     #
#     # without creating any intermediate tensors with O(num_train * num_test) #
#     # elements.                                                              #

#     # x_train_flat = x_train.view(num_train, -1)
#     # x_test_flat = x_test.view(num_test, -1)

#     # x_train_squared = torch.sum(x_train_flat ** 2, dim=1).view(-1, 1)
#     # x_test_squared = torch.sum(x_test_flat ** 2, dim=1).view(1, -1)

#     # dists = x_train_squared + x_test_squared - 2 * torch.mm(x_train_flat, x_test_flat.t())
#     # Assuming x_train and x_test are already defined and have the correct shapes
#     x_train_flat = x_train.view(num_train, -1)  # Reshape x_train to ensure it has shape (20, D)
#     x_test_flat = x_test.view(num_test, -1)  # Reshape x_test to ensure it has shape (10000, D)

#     # Compute the squared sum of x_train and x_test separately
#     x_train_squared = torch.sum(x_train_flat ** 2, axis=1).view(-1, 1)  # Shape (20, 1)
#     x_test_squared = torch.sum(x_test_flat ** 2, axis=1).view(1, -1)  # Shape (1, 10000)

#     # find the dimension of x_train_flat and x_test_flat
#     print(list(x_train_flat.shape))
#     if (x_train_flat.shape[1] != x_test_flat.shape[1]):
#         # make the dimension same by adding zeros
#         if (x_train_flat.shape[1] > x_test_flat.shape[1]):
#             x_test_flat = torch.cat((x_test_flat, torch.zeros(x_test_flat.shape[0], x_train_flat.shape[1] - x_test_flat.shape[1])), 1)
#         else:
#             x_train_flat = torch.cat((x_train_flat, torch.zeros(x_train_flat.shape[0], x_test_flat.shape[1] - x_train_flat.shape[1])), 1)

#     # Compute the dot product between x_train and x_test
#     # Corrected matrix multiplication
#     dists = x_train_squared + x_test_squared - 2 * torch.mm(x_train_flat, x_test_flat.t())  # Shape (20, 10000)

#     return dists

# torch.manual_seed(0)
# x_train_rand = torch.randn(100, 3, 16, 16, dtype=torch.float64)
# x_test_rand = torch.randn(100, 3, 16, 16, dtype=torch.float64)

# dists_two = compute_distances_two_loops(x_train_rand, x_test_rand)
# dists_none = compute_distances_no_loops(x_train_rand, x_test_rand)
# difference = (dists_two - dists_none).pow(2).sum().sqrt().item()
# print('Difference: ', difference)
# if difference < 1e-4:
#   print('Good! The distance matrices match')
# else:
#   print('Uh-oh! The distance matrices are different')

# import time

# def timeit(f, *args):
#     tic = time.time()
#     f(*args)
#     toc = time.time()
#     return toc - tic

# torch.manual_seed(0)
# x_train_rand = torch.randn(500, 3, 32, 32)
# x_test_rand = torch.randn(500, 3, 32, 32)

# two_loop_time = timeit(compute_distances_two_loops, x_train_rand, x_test_rand)
# print('Two loop version took %.2f seconds' % two_loop_time)

# no_loop_time = timeit(compute_distances_no_loops, x_train_rand, x_test_rand)
# speedup = two_loop_time / no_loop_time
# print('No loop version took %.2f seconds (%.1fX speedup)'
#       % (no_loop_time, speedup))

# def predict_labels(dists: torch.Tensor, y_train: torch.Tensor, k: int = 1):
#     """
#     Given distances between all pairs of training and test samples, predict a
#     label for each test sample by taking a MAJORITY VOTE among its `k` nearest
#     neighbors in the training set.

#     In the event of a tie, this function SHOULD return the smallest label. For
#     example, if k=5 and the 5 nearest neighbors to a test example have labels
#     [1, 2, 1, 2, 3] then there is a tie between 1 and 2 (each have 2 votes),
#     so we should return 1 since it is the smallest label.

#     This function should not modify any of its inputs.

#     Args:
#         dists: Tensor of shape (num_train, num_test) where dists[i, j] is the
#             squared Euclidean distance between the i-th training point and the
#             j-th test point.
#         y_train: Tensor of shape (num_train,) giving labels for all training
#             samples. Each label is an integer in the range [0, num_classes - 1]
#         k: The number of nearest neighbors to use for classification.

#     Returns:
#         y_pred: int64 Tensor of shape (num_test,) giving predicted labels for
#             the test data, where y_pred[j] is the predicted label for the j-th
#             test example. Each label should be an integer in the range
#             [0, num_classes - 1].
#     """
#     num_train, num_test = dists.shape
#     y_pred = torch.zeros(num_test, dtype=torch.int64)
#     ##########################################################################
#     # TODO: Implement this function. You may use an explicit loop over the   #
#     # test samples.                                                          #
#     #                                                                        #
#     # HINT: Look up the function torch.topk                                  #
#     for j in range(num_test):
#         _, indices = torch.topk(dists[:, j], k, largest=False)
#         closest_y = y_train[indices]
#         y_pred[j] = torch.mode(closest_y)[0]


#     return y_pred

# torch.manual_seed(0)
# dists = torch.tensor([
#     [0.3, 0.4, 0.1],
#     [0.1, 0.5, 0.5],
#     [0.4, 0.1, 0.2],
#     [0.2, 0.2, 0.4],
#     [0.5, 0.3, 0.3],
# ])
# y_train = torch.tensor([0, 1, 0, 1, 2])
# y_pred_expected = torch.tensor([1, 0, 0])
# y_pred = predict_labels(dists, y_train, k=3)
# correct = y_pred.tolist() == y_pred_expected.tolist()
# print('Correct: ', correct)

# class KnnClassifier:

#     def __init__(self, x_train: torch.Tensor, y_train: torch.Tensor):
#         """
#         Create a new K-Nearest Neighbor classifier with the specified training
#         data. In the initializer we simply memorize the provided training data.

#         Args:
#             x_train: Tensor of shape (num_train, C, H, W) giving training data
#             y_train: int64 Tensor of shape (num_train, ) giving training labels
#         """
#         ######################################################################
#         # TODO: Implement the initializer for this class. It should perform  #
#         # no computation and simply memorize the training data in            #
#         # `self.x_train` and `self.y_train`, accordingly.                    #

#         #YOURCODE
#         self.x_train = x_train
#         self.x_train = y_train

#     def predict(self, x_test: torch.Tensor, k: int = 1):
#         """
#         Make predictions using the classifier.

#         Args:
#             x_test: Tensor of shape (num_test, C, H, W) giving test samples.
#             k: The number of neighbors to use for predictions.

#         Returns:
#             y_test_pred: Tensor of shape (num_test,) giving predicted labels
#                 for the test samples.
#         """
#         y_test_pred = None
#         ######################################################################
#         # TODO: Implement this method. You should use the functions you      #
#         # wrote above for computing distances (use the no-loop variant) and  #
#         # to predict output labels.                                          #

#         #YOURCODE
#         dists = compute_distances_no_loops(self.x_train, x_test)
#         y_test_pred = predict_labels(dists, self.y_train, k)
#         return y_test_pred

#     def check_accuracy(
#         self,
#         x_test: torch.Tensor,
#         y_test: torch.Tensor,
#         k: int = 1,
#         quiet: bool = False
#     ):
#         """
#         Utility method for checking the accuracy of this classifier on test
#         data. Returns the accuracy of the classifier on the test data, and
#         also prints a message giving the accuracy.

#         Args:
#             x_test: Tensor of shape (num_test, C, H, W) giving test samples.
#             y_test: int64 Tensor of shape (num_test,) giving test labels.
#             k: The number of neighbors to use for prediction.
#             quiet: If True, don't print a message.

#         Returns:
#             accuracy: Accuracy of this classifier on the test data, as a
#                 percent. Python float in the range [0, 100]
#         """
#         y_test_pred = self.predict(x_test, k=k)
#         num_samples = y_test.shape[0]
#         num_correct = (y_test == y_test_pred).sum().item()
#         accuracy = (num_correct / num_samples) * 100
#         if not quiet:
#             msg = f"Got {num_correct} / {num_samples} correct; accuracy is {accuracy:.2f}%"
#             print(msg)
#         return accuracy


# num_test = 10000
# num_train = 20
# num_classes = 5

# # Generate random training and test data
# torch.manual_seed(128)
# x_train = torch.rand(num_train, 2)
# y_train = torch.randint(num_classes, size=(num_train,))
# x_test = torch.rand(num_test, 2)
# classifier = KnnClassifier(x_train, y_train)

# # Plot predictions for different values of k
# for k in [1, 3, 5]:
#     y_test = classifier.predict(x_test,k=k)
#     plt.gcf().set_size_inches(8, 8)
#     class_colors = ['r', 'g', 'b', 'k', 'y']
#     train_colors = [class_colors[c] for c in y_train]
#     test_colors = [class_colors[c] for c in y_test]
#     plt.scatter(x_test[:, 0], x_test[:, 1],
#                 color=test_colors, marker='o', s=32, alpha=0.05)
#     plt.scatter(x_train[:, 0], x_train[:, 1],
#                 color=train_colors, marker='*', s=128.0)
#     plt.title('Predictions for k = %d' % k, size=16)
#     plt.show()

import ultralytics
