# 1. Introduction
FE approximation이 pure bending displacement fields를 충분히 approximate 못하면 membrane and shear locking 현상이 발생한다.

quadrilateral element가 triangular element보다 richer strain fields를 가지고 있다.

general shell element를 formulate하기 위해서는 두가지 기본적인 접근법이 있다.
1. superimposing plate bending and membrane actions
2. formulations based on 3D continuum mechanics

superimposing plate bending and membrane actions 방법은 general shell problems에서 실제 solution에 수렴하지 않을 수도 있다.
> Q. why?  
> [Book] (Bathe) The FEA of shells - Fundamentals 참고

formulations based on 3D continuum mechanics의 경우 그대로 사용할 경우 locking 현상이 발생한다. 특히 displacement-based 3-node triangular shell finite element (QUAD3)는 locking 현상이 매우 심하다.

# 4. Simple bending test problems


# Appendix
numerical calculation of the s-norm