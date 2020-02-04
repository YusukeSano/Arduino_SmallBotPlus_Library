# Arduino_SmallBotPlus_Library
This library allows an RDC-104/ATmega32U4 board to control Smallbot+.

このライブラリにより、RDC-104/ATmega32U4ボードでSmallbot+を制御できます。

## Installation_インストール方法
 1. Download the file(.ZIP) from this page.

このページからZIPファイルをダウンロードします。
 
 2. Start Arduino.

Arduinoを起動します。
 
 3. Sketch>Include Library>Add .ZIP Library...

スケッチ＞ライブラリをインクルード＞.ZIP形式のライブラリをインストール...
 
 4. Select this file.

ファイルを選択します。

## Usage_使用方法
**Global**

Define Class.

クラスを定義します。

`SmallBotPlus robot = SmallBotPlus();`

**void setup()**
 - void setup();

Define pinMode.

ピン番号を定義します。

`robot.setup();`

**void loop()**

- int light();

Reading light sensor.

明るさセンサを取得します。

`int light = robot.light();`

 - int slider();

Reading variable resistance (slider).

可変抵抗（スライダー）を取得します。

`int slider = robot.slider();`

 - int sound();

Reading sound sensor.

音センサを取得します。

`int sound = robot.sound();`

 - int resistance();

Reading resistance sensor.

抵抗センサを取得します。

`int resistance = robot.resistance();`

 - long distance(int  mode);

Reading ultrasonic sensor (distance sensor).

超音波センサ（距離センサ）を取得します。

mode = 0 returns the value of the unit [cm], otherwise returns the value of the unit [inch].

mode=0で単位[cm]の値を返し、それ以外は単位[inch]の値を返します。

`long cm = robot.distance(0);`

`long inch = robot.distance(1);`

 - void move(int  Left, int  Right);

Move the robot with Left,Right outputs. (Maximum value: 255)

Left、Rightの出力でロボットを動かします。（最大値：255）

`robot.move(255, 255);`

 - int Linetrace(int  inside, int  outside, int  light);

Robot makes a line trace with inner,outer outputs. (Maximum value: 255)

inside、outsideの出力でロボットがライントレースをします。（最大値：255）

Enter the light sensor value in the third argument.

第3引数には光センサの値を入力してください。

Returns 1 when turning right and -1 when turning left.

右に曲がっているときは1を返し、左に曲がっているときは-1を返します。

`robot.Linetrace(90, 120, robot.light());`

`int way = robot.Linetrace(90, 120, robot.light());`

**Example_使用例**

File>Examples>SmallBotPlus>Linetrace

ファイル＞スケッチ例＞SmallBotPlus＞Linetrace

## Site_サイト
* [Smallbot+](https://jrt.buyshop.jp/items/19030778)
* [JAPAN ROBOTECH](https://sites.google.com/site/japanrobotech2/)

## License_ライセンス
 [MIT license](https://github.com/YusukeSano/Arduino_SmallBotPlus_Library/blob/master/LICENSE "LICENSE")

## Author_著者
* [Yusuke Sano_佐野 友亮](https://github.com/YusukeSano)
* [National Institute of Technology, Fukui College_福井工業高等専門学校](https://www.fukui-nct.ac.jp/)
