# CHAPTER 3. LIE GROUP AND LIE ALGEBRA
https://github.com/artivis/manif

https://www.youtube.com/watch?v=nHOcoIyJj2o

https://norlab.ulaval.ca/research/LieCheatsheet/

## Goal of the Study
- Learn the concept of the Lie group, Lie Algebra, and their applications of Special Orthogonal Group $SO(3)$ and  special Euclidean group $SE(3)$
- Learn the meaning and usage of the BHC (Baker-Campbell-Hausdorff) 
- Learn the perturbation model on Lie algebra
- Using Sophus to perform operations on Lie algebras

## 3.1 Basics of Lie Group and Lie Algebra
This set of transform matrices is also known as the special Euclidean group:

$$SE(3) = \{ T = \begin{bmatrix}
R && t  \\
0^T && 1
\end{bmatrix} \in R^{4\times4} | R \in SO(3),  t \in R^3\}$$

### 3.1.1 A Group
A group is an algebraic structure of one set plus one operator. We denote the set as A and operation as $.$, then group can be denoted as $G=(A, .)$. We can say G is group if satisfies the conditions:
- Closures: For any $\forall a_1, a_2 \in A, a_1.a_2 \in A$
- Combination: For any $\forall a_1, a_2, a_3, \in A, (a_1.a_2).a_3 = a_1.(a_2.a_3)$
- Unit element: there exists an identity element $\exists a_0 \in A$ such that $\forall a \in A, a_0.a = a.a_0 =a$ 
- Inverse element: For any $\forall a \in A, \exists a^{-1} \in A$ such that $a.a^{-1} = a_0$

The rotation matrix set with the normal matrix multipli-
cation form a group. The same for the transformation matrix with matrix multiplication. 


