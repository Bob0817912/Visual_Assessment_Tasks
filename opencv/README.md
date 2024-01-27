# TaskOfOpencv

主要考察大家对OpenCV基本操作的理解

## 回形针计数

![](https://images.null-qwerty.top/phoenix/count.png)

统计图片中回形针的个数，并记录。  
结果例：  
![](https://images.null-qwerty.top/phoenix/count_res.png)

## 形态学处理

![](https://images.null-qwerty.top/phoenix/形态学处理.png)

对该图片进行腐蚀、膨胀、开运算、闭运算，修改算子形状和大小。

算子形状有：交叉形，椭圆形，矩形。具体使用请自行查阅。

## 伽马矫正

对下面两张图进行伽马矫正。

![](https://images.null-qwerty.top/phoenix/伽马校正-1.png)
![](https://images.null-qwerty.top/phoenix/伽马矫正-2.jpg)

结果例：

![](https://images.null-qwerty.top/phoenix/伽马矫正.png)

## 提取口罩
> 有一张放在珍珠棉上的口罩的图片，需要大家能够实现下面这样的效果

![](./img/src.jpg)

转换为

![](https://images.null-qwerty.top/phoenix/mask_result.jpg)
## 可能用到的知识点
1. CMake
   + 这个就不多说了，可以直接百度
2. OpenCV（**这里只是提供思路，可能有别的方法也能做到同样的效果**）
   + 读写图片（tips: 注意可执行文件和图片相对路径的问题）
   + 二值化
   + 形态学滤波
   + 图像轮廓提取
   + 拟合多边形
   + 凸包检测
   + 透视变换

### 提供的参数
口罩的长宽比大致为 17:9

