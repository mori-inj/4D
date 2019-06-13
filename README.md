# 4D

1: hypercube  
2: 16cell  
3: 24cell  
u: xy rotation  
i: xz rotation  
o: yz rotation  
j: xw rotation  
k: yw rotation  
l: zw rotation  
shift + u,i,o,j,k,l: reverse rotation  

* 4차원 상의 정다포체를 3차원에 투영한 것을 3D 프로젝트를 이용해 다시 화면상에 출력
* winapi, C++ 사용
* 이미지  
![alt tag](https://github.com/mori-inj/4D/blob/master/hypercube.PNG)  
![alt tag](https://github.com/mori-inj/4D/blob/master/16cell.PNG)  
![alt tag](https://github.com/mori-inj/4D/blob/master/24cell.PNG)  

  <p align="center">
    <img src="https://raw.githubusercontent.com/mori-inj/mori-inj.github.com/master/8cell.jpg" width="350"/>
    <img src="https://raw.githubusercontent.com/mori-inj/mori-inj.github.com/master/16cell.jpg" width="350"/>
    <br />
    <img src="https://raw.githubusercontent.com/mori-inj/mori-inj.github.com/master/24cell.jpg" width="700"/>
  </p>
* 4차원 상에서 해당 도형의 회전이 3차원에 어떻게 투영되어 보이는지 관찰 가능
* 현재는 좌표와 선분만 옮겨졌는데 [이 영상](https://www.youtube.com/watch?v=0t4aKJuKP0Q)처럼 4차원 도형과 3차원 공간의 교공간과 rendering을 추가하는 것이 목표
