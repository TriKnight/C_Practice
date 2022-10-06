# CHAPTER 3. LIE GROUP AND LIE ALGEBRA
https://github.com/artivis/manif

https://vnav.mit.edu/material/04-05-LieGroups-notes.pdf

https://raw.githubusercontent.com/gaoxiang12/slambook-en/master/slambook-en.pdf

https://www.youtube.com/watch?v=nHOcoIyJj2o

https://norlab.ulaval.ca/research/LieCheatsheet/

https://www.youtube.com/watch?v=QR1p0Rabuww

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

Common groups in the matrix are:
- General Linear Goup GL(n): invertible matrix of $n \times n$ matrix mulplication 
- Special Orthogonal Group SO(n). rotation matrix SO(2) and SO(3)
- Special Euclidean group SE(n). SE(2) and SE(3)

### 3.1.2 Lie Algebra
$R$ is the rotation of a camera that changes continuously overtime. Which function of time $R(t)$. We have

$R(t)R(t)^T =I$

Deriving time on both sides of the equation:

$\dot{R(t)}R(t)^T +R(t)\dot{R(t)}^T = 0$

$\dot{R(t)}R(t)^T = - [\dot{R(t)}R(t)^T]^T$

It can be seen $R(t)\dot{R(t)}^T$ is *shew-symmetric* matrix. Symbol $\times$ in the cross product formula, this turns a vector into a skew-symmetric matrix $\phi_\times$ . The $\dot{R(t)}R(t)^T \in \R^3$ is a skew-symmetric matrix. 

$$
\dot{R(t)}R(t)^T = \phi_\times
$$
Right multiply with $R(t)$ on both sides. R is orthogonal matrix

$$\dot{R}(t) = \phi_\times R(t) = \begin{bmatrix}
0 && -a_3 && a_2  \\
a_3 && 0  && -a_1 \\
-a_2 && a_1 && 0
\end{bmatrix}  R(t)$$

It can be seen that the time derivatice of rotation matrix just multiply $\phi_\times$ matrix on the left. The $\phi_\times$ skew-symmetric matrix is reflects the derivative of $R$, it is called tangent space near origin $SO(3)$. 

![Topology Lie Theory](../img/Topology_Lie_Theory.png)

First-order Taylor expansion 

$$
R(t) = R(t_0) + \dot{R}(t_0)(t-t_0) = I + {\phi(t)}_\times t
= exp({\phi(t)}_\times t)
$$

### 3.1.3 The definition of Lie Algebra ??


# Practice with Sophus

### Install Sophus
* use pangolin: slambook/3rdpart/Pangolin or download it from github: git clone https://github.com/strasdat/Sophus

* compile and install Sophus
cd [path-to-Sophus]
mkdir build
cd build
cmake ..
make 
sudo make install 

* Add to the CMakeLists.txt
```
find_package(Sophus REQUIRED)
include_directories(${Sophus_INCLUDE_DIRS})
target_link_libraries(useSophus ${Pangolin_LIBRARIES})
```

* Config CPP_propertive in VS Code
```
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**",
                "/usr/include/eigen3"
            ],
            "defines": [],
            "compilerPath": "/usr/bin/clang",
            "cStandard": "c17",
            "cppStandard": "c++14",
            "intelliSenseMode": "linux-clang-x64"
        }
    ],
    "version": 4
}
```
## Trajectory Evaluation
A Tutorial on Quantitative Trajectory Evaluation
for Visual(-Inertial) Odometry
https://rpg.ifi.uzh.ch/docs/IROS18_Zhang.pdf
Python package for the evaluation of odometry and SLAM
https://github.com/MichaelGrupp/evo