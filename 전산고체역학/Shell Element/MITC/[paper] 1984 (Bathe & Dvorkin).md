# Basic Considerations
interpolation of the displacement와 derication of the strain-displacement matrices를 사용하는 것의 기본적인 문제는 shell element가 얇아지면 'lock'된다는 점이다. 이는 displacement를 interpolation해서는 transverse shear strains가 constant bending moment가 작용할 때, transverse shear strains가 모든 점에서 0이 되지 않기 때문이다. basic continuum mechanics assumption이 Kirchhoff shell assumptions을 포함하지만 the finite element discretization에서는 이 가정을 represent 할수가 없다.
> Q. constant bending moment가 작용할 때, 왜 transverse shear strains가 0인가?

transverse shear strain을 representation하는데 문제가 있다는 점에 착안하여, displacements로부터 shear strain을 계산해내지 않고 독립적으로 strain을 interpolation한다.

strain을 따로 interpolation했기 때문에 displacement based strain과 coupling하는 작업이 필요하며 이 과정에서 spurious zero energy mode가 나타나지 않게 하는것이 중요하다.