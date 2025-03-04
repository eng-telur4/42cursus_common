## はじめに

MiniLibXが何ができるのかを理解したところで、いくつかの基本的なことから始めていきましょう。これらを学ぶことで、このライブラリを使って効率的なコードを書くための確かな理解を得ることができます。多くのプロジェクトにおいて、パフォーマンスは本質的に重要です。そのため、このセクションをしっかりと読むことが何よりも大切です。

## インストール

### macOSでのコンパイル

MiniLibXはmacOSのCocoa（AppKit）とOpenGLを必要とし、X11は使用しなくなったため、適切にリンクする必要があります。これにより、コンパイルプロセスが複雑になる可能性があります。基本的なコンパイル手順は以下のとおりです。

オブジェクトファイルを作成するには、プロジェクトのルートディレクトリに```mlx```というディレクトリがあり、その中に```mlx```のソースがあることを前提として、Makefileに以下のルールを追加できます。

```Makefile
%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
```

必要なmacOSの内部APIとリンクするには、以下のようにします。

```Makefile
$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
```

なお、```libmlx.dylib```は動的ライブラリであるため、ビルドターゲットと同じディレクトリに配置する必要があることに注意してください。

### Linuxでのコンパイル

Linuxの場合、[Codam提供のzip](https://github.com/42Paris/minilibx-linux "Codam provided zip") を使用できます。これはLinux互換のMLXバージョンで、関数や呼び出し方法は全く同じです。ただし、画像のメモリ管理に関しては、オブジェクトの実装がアーキテクチャ依存であるため、動作が異なる可能性があることに注意してください。次に、```mlx_linux```という新しいフォルダをプロジェクトのルートに作成し、その中にMLX for Linuxを解凍してください。

Linux版MiniLibXは```xorg```, ```x11```, ```zlib```を必要とするため、以下の依存関係をインストールする必要があります：```xorg```, ```libxext-dev```, ```zlib1g-dev```。Ubuntuでは、次のコマンドでこれらをインストールできます。

```shell
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```

次に、MLXを設定する必要があります。提供されたリポジトリのルートで```configure```スクリプトを実行すれば、準備完了です。

オブジェクトファイルを作成するには、プロジェクトのルートディレクトリに```mlx_linux```というディレクトリがあり、その中にLinux版のMLXソースがあることを前提として、Makefileに以下のルールを追加できます。

```Makefile
%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@
```

必要なLinuxの内部APIとリンクするには、以下のようにします。

```Makefile
$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
```

### Windows 10（WSL2）で画面を表示する

Windows 10のWSL2で画面を表示するのは難しい場合があります。可能であれば、グラフィックスサポートが組み込まれているWindows 11を使用するか、仮想マシン（VM）を利用することをおすすめします。

それでもWSL2にはグラフィックスレイヤーがないため、VNCを使用して画面に接続する必要があります。以下の手順を実行してください。

1. [Xming](https://sourceforge.net/projects/xming/ "Xming") をインストールします。デフォルト設定のまま「次へ」をクリックして進めれば問題ありません。インストール後、タスクトレイにXmingのアイコンが表示されます。一度Xmingを終了し、XLaunchを開いて次の手順を進めます。
   - 「```Multiple windows```」を選択して次へ進む
   - 「```Start no client```」を選択して次へ進む
   - 「```No Access Control```」のチェックボックスを有効にして次へ進む
   - 「```Save configuration```」をクリックし、その後「```Finish```」をクリックする

2. WSLで次のコマンドを実行し、ディスプレイ環境変数を適切に設定します（エイリアスを作成しておくと便利です）。
   ```shell
   export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0.0
   ```

3. これで、コマンドラインからグラフィカルアプリケーションを実行できるようになります。

#### 助けて！ それでも動きません！

まず、WSL2を実行していることを確認してください。これについては、[Stack Overflowの投稿](https://askubuntu.com/questions/1177729/wsl-am-i-running-version-1-or-version-2#:~:text=From%20the%20WSL%20shell%20prompt,4.19%2C%20it's%20WSL%20Version%202. "stackoverflow post")が詳しく解説しており、きっと役に立つはずです。もしWSL1を使用している場合は、WSL2にアップグレードすることを強くおすすめします。WSL2の方が大幅に高速であり、今回の問題も解決する可能性があります。

それでもWSL1を使いたい場合は、以下のコマンドでディスプレイをlocalhostに設定することで問題を解決できるかもしれません。

```shell
export DISPLAY=localhost:0.0
```

---

WSL2を実行していることを確認した後、次のコマンドを実行して出力を確認してください。

```shell
$> echo $DISPLAY
```

このコマンドの出力として、IPアドレス（任意の有効なIPアドレス）に続いて「```:0.0```」が表示されるはずです。

もし出力が空であったり、正しいIPアドレスが含まれていない場合は、```/etc/resolv.conf```ファイルが存在しない可能性があります。次のコマンドで内容を確認してください。

```shell
cat /etc/resolv.conf
```

このファイルの内容は、以下のようになっているべきです。

```shell
# This file was automatically generated by WSL. To stop automatic generation of this file, add the following entry to /etc/wsl.conf:
# [network]
# generateResolvConf = false
nameserver 172.27.32.1
```

もしファイルが空であれば、以下のコマンドでWSLの設定ファイルを作成し、PCを再起動してください。

```shell
echo -e -n "[network]\ngenerateResolvConf = true\n" > /etc/wsl.conf
```

**注意：このコマンドの実行にはroot権限が必要です。**

---

ファイルが空でなく、IPアドレスが含まれている場合は、以下のコマンドで直接ディスプレイを設定してみてください。

```shell
export DISPLAY=[YOUR IP]:0.0
```

例えば、```/etc/resolv.conf```のIPアドレスが```172.27.32.1```だった場合、次のようになります。

```shell
export DISPLAY=172.27.32.1:0.0
```

---

もしこれでも問題が解決しない場合は、Slackで(@hsmits)にメッセージを送ってください。

### Windows 11（WSLg）で画面を表示する

Windows 11 の WSL（WSLg）には、Linux の GUI アプリケーションを直接実行するオプションがあります。これを有効にするには、[公式ガイド](https://docs.microsoft.com/en-us/windows/wsl/tutorials/gui-apps) に従って設定してください。

インストールが完了したら、MiniLibX アプリをコンパイルして実行するだけで、Windows 上の通常のアプリケーションのように画面が表示されます。

## 初期化

MiniLibX ライブラリを使用する前に、すべての関数へアクセスできるようにするために ```<mlx.h>``` ヘッダーをインクルードし、```mlx_init``` 関数を実行する必要があります。

この関数を呼び出すことで、適切なグラフィックシステムへの接続が確立され、現在の MLX インスタンスの場所を保持する ```void *``` 型のポインタが返されます。MiniLibX を初期化するには、次のように記述できます。

```c
#include <mlx.h>

int	main(void)
{
	void	*mlx;

	mlx = mlx_init();
}
```

このコードを実行しても、何も表示されず、何も描画されないことに気づくでしょう。これは当然で、まだウィンドウを作成していないためです。

そこで、小さなウィンドウを初期化し、それを開きっぱなしにしてみましょう。ウィンドウを閉じるには、ターミナルで `CTRL + C` を押してください。

これを実現するために、`mlx_new_window` 関数を呼び出します。この関数は、新しく作成したウィンドウのポインタを返します。ウィンドウの幅、高さ、タイトルを指定できます。

また、ウィンドウの描画を開始するために `mlx_loop` を呼び出す必要があります。
以下のコードでは、幅 1920、高さ 1080、タイトル「Hello world!」のウィンドウを作成しています。

```c
#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
}
```

## 画像へのピクセルの書き込み

基本的なウィンドウ管理ができたので、次はウィンドウにピクセルを描画することを始めます。ピクセルをどう取得するかは自由ですが、最適化された方法についても説明します。まず最初に、`mlx_pixel_put` 関数は非常に遅いという点を考慮する必要があります。これは、ピクセルをウィンドウに即座に描画しようとするため（フレームが完全にレンダリングされるのを待たずに）。この理由から、すべてのピクセルをまず画像にバッファリングし、それをウィンドウに描画する必要があります。これを聞くと非常に複雑に思えるかもしれませんが、実際にはそれほど難しくありません。

まず、`mlx` が要求する画像の種類を理解することから始めましょう。画像を初期化する際に、いくつかのポインタを渡し、いくつかの重要な変数に書き込まれます。最初の変数は `bpp`（bits per pixel）で、ピクセルは基本的に整数なので通常は 4 バイトですが、リトルエンディアン（つまり、リモートディスプレイで 8 ビットカラーしか使えない場合）を扱っている場合は異なることがあります。

これで、1920×1080 のサイズで画像を初期化することができます。以下のコードで実行できます。

```c
#include <mlx.h>

int	main(void)
{
	void	*img;
	void	*mlx;

	mlx = mlx_init();
	img = mlx_new_image(mlx, 1920, 1080);
}
```

それほど難しくはなかったですね？さて、画像が手に入りましたが、具体的にどのようにしてピクセルを書き込むのでしょうか？これを行うには、バイトを適切に変更するためにメモリアドレスを取得する必要があります。このアドレスは次のように取得します：

```c
#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	main(void)
{
	void	*mlx;
	t_data	img;

	mlx = mlx_init();
	img.img = mlx_new_image(mlx, 1920, 1080);

	/*
	** 画像を作成した後、`mlx_get_data_addr`を呼び出すことができます。
	** `bits_per_pixel`、`line_length`、`endian`を参照渡しします。
	** これにより、*現在の*データアドレスが設定されます。
	*/
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
}
```

```bits_per_pixel```, ```line_length```, ```endian```の変数を参照渡ししているのに注目してください。これらは、上記のようにMiniLibXによって適切に設定されます。

これで画像のアドレスは得られましたが、まだピクセルはありません。この作業を始める前に、バイトが整列されていないことを理解する必要があります。つまり、```line_length```は実際のウィンドウの幅と異なります。したがって、```mlx_get_data_addr```で設定されたライン長を使用して、常にメモリオフセットを計算する必要があります。

次の式を使えば、非常に簡単に計算できます：

```c
int offset = (y * line_length + x * (bits_per_pixel / 8));
```

どこに書き込むかがわかったので、```mlx_pixel_put```の動作を模倣する関数を書くのは非常に簡単になりますが、この関数は単に何倍も速く動作します：

```c
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
```

これには問題が生じることに注意してください。画像はウィンドウでリアルタイムに表示されるため、同じ画像を変更すると、書き込み時に画面が引き裂かれる現象が発生します。したがって、フレームを一時的に保持するために2枚以上の画像を作成するべきです。その後、一時的な画像に書き込むことで、現在表示されている画像に書き込む必要がなくなります。

## ウィンドウへの画像の表示

```c
#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
```

```0x00FF0000```は```ARGB(0,255,0,0)```の16進数表現であることに注意してください。

## スキルを試してみよう！

基本を理解したので、ライブラリに慣れて、いろいろな面白いことをしてみましょう！いくつかのアイデアを紹介します：

- ピクセルを適切に書き込んで、画面に四角形、円、三角形、六角形を描画してみましょう。
- グラデーションを追加したり、虹を作ったり、rgbカラーを使うことに慣れてみましょう。
- ループで画像を生成して、テクスチャを作成してみましょう。
