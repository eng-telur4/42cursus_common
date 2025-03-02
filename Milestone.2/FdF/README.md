# FdF

Wireframe model

Summary:

This project is about representing a landscape as a 3D object in which a;; surfaces are outlined in lines.

Version: 3

## Chapter Ⅰ - Foreword

This is what Wikipedia says about Ghosts’n Goblins:

Ghosts’n Goblins is a platform game where the player controls a knight, named Sir Arthur, who must defeat zombies, ogres, demons, cyclops, dragons and other monsters in order to rescue Princess Prin Prin, who has been kidnapped by Satan, king of Demon World. Along the way the player can pick up new weapons, bonuses and extra suits of armor that can help in this task.

The game is often considered very difficult by arcade standards and is commonly regarded as one of the most difficult games ever released.

The player can only be hit twice before losing a life (the first hit takes away Arthur’s armor, and the player must continue on wearing underwear until completing the level or finding replacement armor). If the player loses a life, they start all over again, or from the halfway point if they managed to get that far.

Furthermore, each life can only last a fixed duration (generally around three minutes), the clock being reset at the start of a level. If the clock does run out, the player instantly loses that life.

After defeating the final boss, but only with the cross weapon (if the player does not have the cross weapon, they will be prompted that it is needed to defeat the boss and restart at the beginning of level 5 and must repeat round 5 and 6 again regardless if the weapon is obtained immediately or not) for the first time the player is informed that the battle was a trap devised by Satan. The player must then replay the entire game on a higher difficulty level to reach the genuine final battle.

- Ports\
Many conversions to home computers were produced by Elite Systems.\
  - The Commodore 64 version, released in 1986, is known for its music by Mark Cooksey, which borrows from Frédéric Chopin’s Prelude No. 20. Due to the limited resources on the Commodore 64, it was somewhat different from the arcade version. It only features the Graveyard and Forest, The Ice Palace, The Floating Platforms and Firebridge and The Caves in that order. The player also starts the game with five lives. The demon that kidnapped the princess replaces Astaroth in the title screen. Additionally, the cyclops (or Unicorn) is the boss of levels one to three and the dragon is the final boss.
  - The version for Commodore 16/116 and Commodore Plus/4, also released in 1986 by Elite Systems, was even more limited than the C64 version. It was written to work on a Commodore 16, which had only 16 KB of RAM. Therefore, this version features only two levels and no music. In addition, the remaining two levels and the gameplay are simplified. For example, in the graveyard level, the attacking bird, the plant monsters and the winged demon are all missing from the C16 version, and there is only one weapon. The title screen features no graphics besides the stylised Ghosts ’n Goblins lettering.
  - A version for the Commodore Amiga was released in 1990. While the advanced hardware of the Amiga allowed an almost perfect conversion of the arcade game, it failed to emulate the success of the Commodore 64 version. The player starts the game with six lives and no music is played unless the Amiga was equipped with at least 1 Megabyte of RAM. The standard configuration of an Amiga 500 was 512 Kilobytes.
  - The NES version was developed by Micronics. This also serves as the basis for the Game Boy Color version, which uses passwords to allow the player to jump to certain levels. The NES version was ported to the Game Boy Advance as part of Classic NES series, but only in Japan.
  - The NES version was also re-released for download for Nintendo’s Virtual Console in North America on December 10, 2007 (Wii) and October 25, 2012 (Nintendo 3DS) and in the PAL region on October 31, 2008 (Wii) and January 3, 2013 (Nintendo 3DS) while the Wii U version was released in both regions on May 30, 2013. The arcade version was released on the Wii’s Virtual Console Arcade in Japan on November 16, 2010, the PAL region on January 7, 2011 and in North America on January 10, 2011.
  - Ghosts’n Goblins was also ported to the ZX Spectrum, Amstrad CPC, MSX, Atari ST, IBM PC compatibles, Game Boy Color, Game Boy Advance. The original arcade version of the game was also included in the compilation Capcom Generations Vol.2: Chronicles of Arthur for the PlayStation (in Japan and Europe) and Sega Saturn (in Japan only), which also contained Ghouls’n Ghosts and Super Ghouls’n Ghosts. The three games (based on their Capcom Generation versions) were later collected as part of Capcom Classics Collection. The game was also featured in the compilation Capcom Arcade Cabinet for the PlayStation 3 and Xbox 360.

- Reception\
Computer Gaming World called Ghosts’n Goblins "an excellent example of what the [NES] can do ... while hardly groundbreaking, represents the kind of game that made Nintendo famous".\
Ghosts ’n Goblins was runner-up in the category of Arcade-Style Game of the Year at the Golden Joystick Awards. The NES version of Ghosts ’n Goblins was rated the 129th best game made on a Nintendo System in Nintendo Power’s Top 200 Games list. It was also a best seller for the NES, selling 1.64 million units.\
Ghosts ’n Goblins is often cited as an example of one of the most difficult games of all time to beat, due to its extreme level of difficulty and the fact the player must play through the game twice in order to beat the game.

- Legacy\
Ghosts’n Goblins was followed by a series of sequels and spin-offs eventually becoming Capcom’s 8th best-selling game franchise, selling over 4.4 million units. Its sequels include Ghouls’n Ghosts, Super Ghouls’n Ghosts, and Ultimate Ghosts’n Goblins in addition to producing the Gargoyle’s Quest and Maximo spin-off series. Though originating as an arcade title, the franchise has been featured on a variety of PC and video game consoles with the latest entries in the series, Ghosts ’n Goblins: Gold Knights, released on the iOS. Additionally, the franchise frequently makes cameo appearances — the character of Arthur in particular — in other Capcom titles, the latest of which being Ultimate Marvel vs. Capcom 3.

## Chapter Ⅱ - Introduction

The representation in 3D of a landscape is a critical aspect of modern mapping. For example, in these times of spatial exploration, to have a 3D representation of Mars is a prerequisite condition to its conquest.

As another example, comparing various 3D representations of an area of high tectonic activity will allow you to better understand these phenomena and their evolution, and as a result, be better prepared.

It’s your turn today to modelize some 3D magnificent landscapes, imaginary or not.

FDF is short for ’fil de fer’ in French which means ’wireframe model’.

## Chapter Ⅲ - Objectives

It’s time for you to create a basic computer graphics project!

You are going to use the school graphical library: the MiniLibX! This library was developed internally and includes basic necessary tools to open a window, create images and deal with keyboard and mouse events.

This will be the opportunity for you to get familiar with the MiniLibX, to discover the basics of graphics programming, especially how to place points in space, join them and, most important, how to see the scene from a specific viewpoint.

## Chapter Ⅳ - Common Instructions

- Your project must be written in C.
- Your project must be written in accordance with the Norm. If you have bonus files/functions, they are included in the norm check and you will receive a 0 if there is a norm error inside.
- Your functions should not quit unexpectedly (segmentation fault, bus error, double free, etc) apart from undefined behaviors. If this happens, your project will be considered non functional and will receive a 0 during the evaluation.
- All heap allocated memory space must be properly freed when necessary. No leaks will be tolerated.
- If the subject requires it, you must submit a Makefile which will compile your source files to the required output with the flags -Wall, -Wextra and -Werror, use cc, and your Makefile must not relink.
- Your Makefile must at least contain the rules $(NAME), all, clean, fclean and re.
- To turn in bonuses to your project, you must include a rule bonus to your Makefile, which will add all the various headers, librairies or functions that are forbidden on the main part of the project. Bonuses must be in a different file _bonus.{c/h} if the subject does not specify anything else. Mandatory and bonus part evaluation is done separately.
- If your project allows you to use your libft, you must copy its sources and its associated Makefile in a libft folder with its associated Makefile. Your project’s Makefile must compile the library by using its Makefile, then compile the project.
- We encourage you to create test programs for your project even though this work won’t have to be submitted and won’t be graded. It will give you a chance to easily test your work and your peers’ work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating.
- Submit your work to your assigned git repository. Only the work in the git repository will be graded. If Deepthought is assigned to grade your work, it will be done after your peer-evaluations. If an error happens in any section of your work during Deepthought’s grading, the evaluation will stop.

## Chapter Ⅴ - Mandatory part

- [Program name] fdf
- [Turn in files] Makefile, *.h, *.c
- [Makefile] NAME, all, clean, fclean, re
- [Arguments] A file in format *.fdf
- [External functs.]
  - open, close, read, write, malloc, free, perror, strerror, exit
  - All functions of the math library (-lm compiler option, man man 3 math)
  - All functions of the MiniLibX
  - ft_printf and any equivalent YOU coded
- [Libft authorized] Yes
- [Description] This project is about creating a simple wireframe model of a landscape.

This project is about creating a simple wireframe model representation of a 3D landscape
by linking various points (x, y, z) thanks to line segments (edges).

Your project must comply with the following rules:

- You must use the MiniLibX. Either the version available on the school machines,
or installing it using its sources.
- You have to turn in a Makefile which will compile your source files. It must not
relink.
- Global variables are forbidden.

1. Rendering

Your program has to represent the model in isometric projection.

The coordinates of the landscape are stored in a .fdf file passed as a parameter to your program. Here is an example:

```shell
$>cat 42.fdf
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
$>
```

Each number represents a point in space:

- The horizontal position corresponds to its axis.
- The vertical position corresponds to its ordinate.
- The value corresponds to its altitude.

Executing your fdf program using the example file 42.fdf:

```shell
$> ./42.fdf
$>
```

Should render a landscape simmilar to:

Remember to use of your libft the best way you can! Using get_next_line(), ft_split() and other functions will allow you to read data from the file in a quick and simple way.

Keep in mind that the goal of this project is not to parse maps! However, this doesn’t mean that your program should crash when run. It means that we assume the map contained in the file is properly formatted.

2. Graphic management

- Your program has to display the image in a window.
- The management of your window must remain smooth (changing to another window, minimizing, and so forth).
- Pressing ESC must close the window and quit the program in a clean way.
- Clicking on the cross on the window’s frame must close the window and quit the program in a clean way.
- The use of the images of the MiniLibX is mandatory.

On the intranet project page, a binary file called fdf as well as the example file 42.fdf inside a fdf.zip are available to download.

## Chapter Ⅵ - Bonus part

Usually, you would be encouraged to develop your own original extra features. However,　there will be much more interesting graphic projects later. They are waiting for you!!

Don’t lose too much time on this assignment!

You are allowed to use other functions to complete the bonus part as long as their　use is justified during your evaluation. Be smart!

You will get some extra points if you can:
- Include one extra projection (such as parallel or conic)!
- Zoom in and out.
- Translate your model.
- Rotate your model.
- Add one more bonus of your choice.

The bonus part will only be assessed if the mandatory part is　PERFECT. Perfect means the mandatory part has been integrally done　and works without malfunctioning. If you have not passed ALL the　mandatory requirements, your bonus part will not be evaluated at all.

## Chapter Ⅶ - Submission and peer-evaluation

Turn in your assignment in your Git repository as usual. Only the work inside your repository will be evaluated during the defense. Don’t hesitate to double check the names of your files to ensure they are correct.

As these assignments are not verified by a program, feel free to organize your files as you wish, as long as you turn in the mandatory files and comply with the requirements.

file.bfe:VADYjxBiOQSAWNqB652klCj13URaziELdHd+2Z38XCMD9dvO9tSyFob6Il3NBX9YXrgZEiQK7JZJ7w5t0N80wMl7

# FdF

ワイヤーフレームモデル

概要

このプロジェクトは、風景を3Dオブジェクトとして表現することである。

バージョン: 3

## Chapter Ⅰ - Foreword

これはウィキペディアのGhosts'n Goblinsに関する記述です：

Ghosts'n Goblinsは、プレイヤーがアーサー卿という名の騎士を操り、魔界の王サタンにさらわれたプリンセス・プリンを救出するために、ゾンビ、オーガ、悪魔、サイクロプス、ドラゴンなどのモンスターを倒していくプラットフォームゲームである。道中、プレイヤーは新しい武器やボーナス、この任務に役立つ追加防具を手に入れることができる。

このゲームはアーケードの基準からすると非常に難しく、これまでに発売されたゲームの中で最も難しいゲームのひとつとされている。

プレイヤーはライフを失うまで2回しか攻撃を受けることができない（1回目の攻撃でアーサーのアーマーは奪われ、プレイヤーはレベルをクリアするか代わりのアーマーを見つけるまで下着を着続けなければならない）。ライフを失った場合、プレイヤーはもう一度最初からやり直すか、そこまでたどり着いていれば途中からやり直すことになる。

さらに、各ライフの持続時間は決まっており（一般的には3分程度）、レベル開始時にリセットされる。クロックが切れると、プレイヤーは即座にそのライフを失う。

最後のボスを倒した後、十字架の武器（十字架の武器を持っていない場合、ボスを倒すのに必要であることが表示され、レベル5の最初からやり直しになる。その後、プレイヤーは正真正銘の最終決戦に到達するために、より高い難易度でゲーム全体をリプレイしなければならない。

- Ports
エリート・システムズ社により、家庭用コンピュータへのコンバージョンが多数制作された。
  - 1986年に発売されたコモドール64版は、フレデリック・ショパンの前奏曲第20番を引用したマーク・クックシーによる音楽で知られる。コモドール64のリソースが限られていたため、アーケード版とは多少異なる。墓場と森」、「氷の宮殿」、「浮遊台と火の橋」、「洞窟」の順にしか登場しない。また、プレイヤーは5つのライフを持ってゲームを開始する。タイトル画面では、姫をさらった悪魔がアスタロトに代わって登場する。さらに、サイクロプス（またはユニコーン）がレベル1から3のボスで、ドラゴンがラスボスである。
  - 同じく1986年にエリートシステムズから発売されたコモドール16/116とコモドールプラス/4用のバージョンは、C64バージョンよりもさらに制限されていた。RAMが16KBしかないコモドール16で動くように書かれていた。そのため、このバージョンには2つのレベルしかなく、音楽もない。さらに、残りの2つのレベルとゲームプレイは簡略化されている。たとえば、墓場レベルでは、襲ってくる鳥、植物の怪物、翼のある悪魔がC16版にはなく、武器も1つしかない。タイトル画面には、スタイル化されたGhosts 'n Goblinsの文字以外にグラフィックはない。
  - 1990年にはコモドール・アミーガ版も発売された。Amigaの先進的なハードウェアにより、アーケードゲームをほぼ完璧に変換することができたが、コモドール64版の成功を模倣することはできなかった。プレイヤーは6つのライフでゲームを開始し、Amigaに少なくとも1メガバイトのRAMが搭載されていなければ音楽は流れない。アミーガ500の標準構成は512キロバイトだった。
  - ファミコン版はマイクロニクスが開発した。これはゲームボーイカラー版のベースにもなっており、パスワードを使って特定のレベルにジャンプできるようになっている。ファミコン版はクラシックファミコンシリーズの一環としてゲームボーイアドバンスに移植されたが、日本でのみ発売された。
  - また、北米では2007年12月10日（Wii）と2012年10月25日（ニンテンドー3DS）に、PAL地域では2008年10月31日（Wii）と2013年1月3日（ニンテンドー3DS）に、Wii U版は2013年5月30日に両地域で発売された。アーケード版はWiiのバーチャルコンソールアーケードで日本では2010年11月16日に、PAL地域では2011年1月7日に、北米では2011年1月10日に発売された。
  - Ghosts'n Goblins』はZX Spectrum、Amstrad CPC、MSX、Atari ST、IBM PC互換機、ゲームボーイカラー、ゲームボーイアドバンスにも移植された。また、オリジナルのアーケード版は、プレイステーション（日本とヨーロッパ）とセガサターン（日本のみ）向けのコンピレーション『カプコン ジェネレーションズ Vol.2: クロニクル オブ アーサー』に収録され、『グールズンゴースト』と『スーパーグールズンゴースト』も収録された。この3つのゲーム（カプコン・ジェネレーション版に基づく）は後に『カプコンクラシックスコレクション』の一部として収録された。また、PlayStation 3とXbox 360向けのコンピレーション『カプコン アーケード キャビネット』にも収録された。

- 受付\
Computer Gaming Worldは『Ghosts'n Goblins』を「（ファミコンに）何ができるかを示す優れた例である......画期的とは言い難いが、任天堂を有名にしたゲームの一種である」と評した。\
Ghosts 'n GoblinsはGolden Joystick AwardsのArcade-Style Game of the Year部門で準優勝。ファミコン版『Ghosts 'n Goblins』は、Nintendo Power誌の「トップ200ゲーム」において、任天堂システムで作られたゲームの中で129番目に良いゲームと評価された。また、ファミコンのベストセラーとなり、164万本を売り上げた。\
Ghosts 'n Goblins」は、その難易度の高さと、ゲームをクリアするために2回プレイしなければならないことから、「史上最も難しいゲーム」の例として挙げられることが多い。

- レガシー\
Ghosts'n Goblins』はその後、続編やスピンオフ作品が続々と発売され、最終的にはカプコンで8番目に売れたゲームフランチャイズとなり、440万本以上を売り上げた。続編には『Ghouls'n Ghosts』、『Super Ghouls'n Ghosts』、『Ultimate Ghosts'n Goblins』があり、さらに『Gargoyle's Quest』や『Maximo』のスピンオフシリーズも制作された。アーケードタイトルとして誕生したこのフランチャイズは、様々なPCやゲーム機で展開され、シリーズ最新作の『Ghosts 'n Goblins』はiOSでリリースされた： Ghosts'n'Goblins:GoldKnights』はiOSでリリースされた。さらに、同シリーズはカプコンの他タイトルにも度々カメオ出演しており、特にアーサーというキャラクターは最新作の『アルティメット マーヴル VS カプコン3』にも登場している。

## Chapter Ⅱ - Introduction

景観を3Dで表現することは、現代の地図作成において非常に重要な要素である。例えば、空間探査の時代において、火星を3Dで表現することは、火星を征服するための必須条件である。

別の例として、地殻変動が激しい地域の様々な3D表現を比較することで、これらの現象やその進化をよりよく理解することができ、その結果、よりよい準備ができます。

今日は、架空のものであれ、そうでないものであれ、3Dの壮大な風景をモデリングする番です。

FDFはフランス語で「fil de fer」の略で、「ワイヤーフレームモデル」を意味します。

## Chapter Ⅲ - Objectives

基本的なコンピュータグラフィックスプロジェクトを作成する時間です！

学校のグラフィカルライブラリであるMiniLibXを使用します！このライブラリは内部で開発されたもので、ウィンドウを開いたり、画像を作成したり、キーボードやマウスのイベントを処理したりするために必要な基本的なツールが含まれています。

この機会にMiniLibXに慣れ親しみ、グラフィックプログラミングの基本、特に空間に点を配置する方法、点を結合する方法、そして最も重要な、特定の視点からシーンを見る方法を発見してください。

## Chapter Ⅳ - Common Instructions

- あなたのプロジェクトはC言語で書かれていなければなりません。
- あなたのプロジェクトは規範に従って書かれていなければなりません。ボーナスファイル/関数がある場合、それらは規範チェックに含まれ、内部に規範エラーがある場合は0が返されます。
- 関数は、未定義の動作とは別に、予期せぬ終了（セグメンテーションフォールト、バスエラー、ダブルフリーなど）をしてはいけません。このような場合、プロジェクトは非機能とみなされ、評価中に0が返されます。
- ヒープに割り当てられたメモリ空間は、必要なときに適切に解放しなければなりません。リークは許されません。
- 課題によって必要な場合、ソースファイルを必要な出力にコンパイルする Makefile を -Wall、-Wextra、-Werror フラグ付きで提出し、cc を使用し、Makefile を再リンクしてはいけません。
- Makefile には少なくとも $(NAME)、all、clean、fclean、re のルールが含まれていなければなりません。
- プロジェクトにボーナスを投入するには、Makefile にボーナスというルールを追加する必要があります。ボーナスでは、プロジェクトのメイン部分で禁止されているさまざまなヘッダ、ライブラリ、関数がすべて追加されます。ボーナスは、対象が他に何も指定しない場合は、別のファイル _bonus.{c/h} に記述する必要があります。必須パートとボーナスパートの評価は別々に行われます。
- あなたのプロジェクトで libft を使用できる場合は、そのソースと関連する Makefile を libft フォルダにコピーして、関連する Makefile と一緒にしなければなりません。あなたのプロジェクトの Makefile は、その Makefile を使ってライブラリをコンパイルし、それからプロジェクトをコンパイルしなければなりません。
- この作業は提出する必要はなく、採点もされませんが、 プロジェクトのテストプログラムを作成することをお勧めします。自分の作品や仲間の作品を簡単にテストすることができます。これらのテストは、ディフェンスの際に特に役立ちます。実際、ディフェンスの際には、あなたが作成したテストや、あなたが評価する仲間のテストを自由に使用することができます。
- あなたの作品を指定された git リポジトリに提出してください。git リポジトリにある作品のみが採点されます。Deepthoughtがあなたの作品の採点を担当する場合、採点はあなたの相互評価後に行われます。Deepthoughtがあなたの作品を採点している間に、あなたの作品のいずれかのセクションでエラーが発生した場合、評価は中断されます。

## Chapter Ⅴ - Mandatory part

- [プログラム名] fdf
- [ファイル名] Makefile, *.h, *.c
- [Makefile] NAME、all、clean、fclean、re
- [引数] *.fdf 形式のファイル
- [外部関数]
  - open、close、read、write、malloc、free、perror、strerror、exit
  - math ライブラリの全関数 (-lm コンパイラオプション, man man 3 math)
  - MiniLibXのすべての関数
  - ft_printf および同等の YOU コード
- [Libft 認証] はい
- [説明] このプロジェクトは風景のシンプルなワイヤーフレームモデルを作成するものです。

このプロジェクトは、様々な点（x、y、z）を線分（エッジ）で結ぶことによって、3D風景のシンプルなワイヤーフレームモデルを作成するものです。
様々な点（x、y、z）を線分（エッジ）で結ぶことによって、3Dの風景をシンプルなワイヤフレームモデルで表現することです。

あなたのプロジェクトは以下のルールに従わなければなりません：

- MiniLibXを使用すること。学校のマシンで利用可能なバージョン、
またはそのソースを使ってインストールすること。
- ソースファイルをコンパイルする Makefile を提出すること。また
再リンクしてはいけません。
- グローバル変数は禁止されています。

1. レンダリング

あなたのプログラムはモデルを等角投影で表現しなければならない。

風景の座標はプログラムのパラメータとして渡される.fdfファイルに保存されます。以下に例を示します：

```shell
$>cat 42.fdf
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
$>
```

各数字は空間上の点を表す：

- 水平位置はその軸に対応する。
- 垂直位置はその縦座標に対応する。
- 値は高度に対応する。

サンプルファイル42.fdfを使ってfdfプログラムを実行する：

```shell
$> ./42.fdf
$>
```

に似た風景をレンダリングするはずだ：

libft をできる限りうまく使うことを忘れないでください！get_next_line()やft_split()などの関数を使えば、ファイルから素早く簡単にデータを読み込むことができます。

このプロジェクトの目的は、マップを解析することではないことを覚えておいてほしい！しかし、これはプログラムを実行するとクラッシュするという意味ではありません。ファイルに含まれる地図が適切にフォーマットされていることを前提にしているということだ。

2. グラフィックの管理

- あなたのプログラムは画像をウィンドウに表示しなければなりません。
- ウィンドウの管理はスムーズでなければなりません（別のウィンドウに変更する、最小化など）。
- ESCキーを押すとウィンドウが閉じ、プログラムが終了します。
- ウィンドウの枠にある十字をクリックすると、ウィンドウが閉じ、プログラムが終了します。きれいな方法でプログラムを終了します。
- MiniLibXの画像の使用は必須です。

イントラネットのプロジェクトページでは、fdf.zip内のサンプルファイル42.fdfとfdfというバイナリファイルをダウンロードできます。

## Chapter Ⅵ - Bonus part

通常は、自分のオリジナルの追加機能を開発することが奨励される。しかし、後にはもっと面白いグラフィック・プロジェクトがあります。それらがあなたを待っているのです

この課題ではあまり時間を無駄にしないでください！

ボーナスパートを完成させるために他の機能を使っても構いません。賢くなりましょう！

そうすれば、追加点がもらえます：
- 平行投影や円錐投影を1つ追加する！
- ズームイン、ズームアウト
- モデルを平行移動する。
- モデルを回転させる。
- 好きなボーナスを1つ追加する。

ボーナス部分は、必須部分が完璧である場合にのみ評価されます。パーフェクトとは、必須パートが統合的に行われ、誤動作することなく動作することを意味します。必須条件をすべてクリアしていない場合、ボーナスパートはまったく評価されません。

## Chapter Ⅶ - Submission and peer-evaluation

通常通り、Gitリポジトリに課題を提出してください。あなたのリポジトリ内の作品だけが、ディフェンス中に評価されます。ファイル名が正しいかどうか、ためらわずにダブルチェックしてください。

これらの課題はプログラムによって検証されないので、必須ファイルを提出し、要件を遵守している限り、ファイルを自由に整理してください。

file.bfe:VADYjxBiOQSAWNqB652klCj13URaziELdHd+2Z38XCMD9dvO9tSyFob6Il3NBX9YXrgZEiQK7JZJ7w5t0N80wMl7

### 参考サイト

- [MiniLibX | 42 Docs](https://harm-smits.github.io/42docs/libs/minilibx "MiniLibX | 42 Docs")
- [MiniLibXの初期使用時](https://qiita.com/yickey/items/fb07e06ea8a646335a5e "【42 東京】Linux環境でminilibxを使用する #42tokyo - Qiita")
