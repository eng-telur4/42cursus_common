# ft_printf

## Chapter Ⅰ - Introduction

You will discover a popular and versatile "C" function: "printf()". This exercise is a great opportunity to improve your programming skills. It is of moderate difficulty.
You will discover "variadic functions" in C.
The key to a successful ft_printf" is a well-structured and extensible code.

One\ce this assignment passwd, you will be allowed to add your ft_printf() to your libft so you can use it in your school C projects.

## Chapter Ⅱ - Common Instructions

- Your project must be written in C;
- Your project must be written in accordance with the Norm. If you have bonus file/functions, they are included in the norm check and you will receive a 0 if there is a norm error inside.
- Your functions should not quit unexxpectedly (sefmentation fault, bus error, double free, etc) apart from undefined behaviors. If this happens, your project will be considered non functional and will receive a 0 during the evaluation.
- All heap allocated memory space must be properly freed when necessary. No loaks will be tolerated.
- If the subject requires it, you must submit a "Makefile" which will compile your source files to the required output with the flags "-Wall", "-Wextra" and "-Werror", use cc, and your Makefile must not relink.
- Your "Makefile" must at least contain the rules "$(NAME)", "all", "clean", "fclean" and "re".
- TO turn in bonuses to your project, you must include a rule "bonus" to your Makefile, which will add all the various headers, librairies or functions that are forbidden on the main part of the project. Bonuses must be in a different file "_bonus.{c/h}" if the subject does not specify anything else. Mandatory and bonus part evaluation is done separately.
- If your project allows you to user your libft, you must copy its sources and its associated "Makefile" in a "libft" folder with its associated Makefile. Your project's "Makefile" must compile the library by using "Makefile", the compile the project.
- We encourage you to create test programe for your project even though this work "won't hae to be submitted and won't be graded". It will give you a chance to easily test your work and your peers' work. You will find those tests especially useful during your defence. Indeed, during defence, your are free to user your tests and/or the tests of the peer you are evaluating.
- Submit your work to your assigned git repository. Only the work in the git repository will be graded. If Deepthought is assigned to grade your work, it will be done after your peer-evaluations. If an error happens in any section of your work during Deepthought's grading, the evaluation will stop.

## Chapter Ⅲ - Mandatory part

1. \
   - [Program name] libftprintf.a
   - [Turn in files] Makefile, *.h, */*.h, *.c, */*.c
   - [Makefile] NAME, all, clean, fclean, re
   - [External functs.] malloc, free, write, va_start, va_arg, va_copy, va_end
   - [Libft authorized] Yes
   - [Desctiption] Write a library that contains ft_printf(), a function that will mimic the original printf()

2. You hae to recode the "printf()" function from libc.
3. The prototype of "ft_printf()" is: "int ft_printf(const char *, ...);"
4. Here are the requirements:
   - Don't implement the buffer management of the original printf().
   - Your function has to handle the following conversions: "cspdiuxX%"
   - Your function will be compared against the priginal "printf()".
   - You must use the command "ar" to create your library. Using the "libtool" command is forbidden.
   - Your "libftprintf.a" has to be created at the root of your repository.
5. You have to implement the following conversions:
   - "%c" Prints a single character.
   - "%s" Prints a string (as defined by the common C convention).
   - "%p" The "void *" pointer argument has to be printed in hexadecimal format.
   - "%d" Prints a decimal (base 10) number.
   - "%i" Prints an integer in base 10.
   - "%u" Prints an unsigned decimal (base 10) number.
   - "%x" Prints a number in hexadecimal (base 16) lowercase format.
   - "%X" Prints a number in hexadecimal (base 16) uppwecase format.
   - "%%" Prints a percent sign.

## Chapter Ⅳ - Bonus part

1. You don't habe to do all the bonuses.
Bonus list:
- Manage any combination of the following flags: "-0." and the field minimum width under all conversions.
- Manage all the following flags: "# +" (Yes, one of them is a space)

2. If you plan to complete the bonus part, think about the implementation of your extra features from the start. This way, you will avoid the pitfalls of a naive approach.
3. The bonus part will only be assessed if the mandatory part is PERFECT. Perfect means the mandatory part has been integrally done and works without malfunctioning. If you have not passed ALL the mandatory requirements, your bonus part will not be evaluated at all.

# ft_printf

## Chapter Ⅰ - Introduction

よく使われ、多用途な 「C 」関数を発見するだろう： 「printf()」です。この練習問題は、あなたのプログラミング・スキルを向上させる絶好の機会です。難易度は中程度です。
C言語の「変種(可変長引数)関数」を発見するでしょう。
printf "を成功させる鍵は、よく構造化され、拡張可能なコードです。

この課題をクリアしたら、ft_printf()をlibftに追加して、学校のCプロジェクトで使用することができます。

## Chapter Ⅱ - Common Instructions

- あなたのプロジェクトはC言語で書かれていなければなりません；
- あなたのプロジェクトは規範に従って書かれていなければなりません。ボーナスファイル/関数がある場合、それらは規範チェックに含まれ、内部に規範エラーがある場合は0が返されます。
- あなたの関数は、未定義の動作とは別に、予期せぬ終了（sefmentation fault、bus error、double freeなど）をしてはいけません。このような場合、プロジェクトは非機能とみなされ、評価中に0が返されます。
- ヒープに割り当てられたすべてのメモリ空間は、必要なときに適切に解放されなければなりません。ループは許されません。
- 課題によって必要な場合は、ソースファイルを必要な出力にコンパイルする「Makefile」を、「-Wall」、「-Wextra」、「-Werror」のフラグ付きで提出しなければなりません。
- Makefile には、少なくとも 「$(NAME)」、「all」、「clean」、「fclean」、「re」 というルールが含まれていなければなりません。
- プロジェクトにボーナスを追加するには、Makefile に 「bonus」 というルールを追加する必要があります。このルールは、プロジェクトのメインパートで禁止されている、さまざまなヘッダー、ライブラリ、関数をすべて追加します。ボーナスは、対象が他に何も指定しない場合は、別のファイル 「_bonus.{c/h}」 にする必要があります。必須パートとボーナスパートの評価は別々に行われます。
- あなたのプロジェクトで libft を使用できる場合は、そのソースと関連する 「Makefile」 を 「libft」 フォルダに関連する Makefile と一緒にコピーする必要があります。プロジェクトの 「Makefile 」は、「Makefile 」を使用してライブラリをコンパイルし、プロジェクトをコンパイルしなければなりません。
- この作業は「提出する必要はなく、採点もされません」が、プロジェクトのテストプログラムを作成することをお勧めします。自分の作品や仲間の作品を簡単にテストすることができます。このようなテストは、ディフェンスの際に特に役立ちます。実際、ディフェンスの際には、自分のテストや評価する仲間のテストを自由に使用することができます。
- 自分の作品を指定された git リポジトリに提出してください。git リポジトリにある作品のみが採点されます。Deepthought があなたの作品の採点を担当することになった場合、採点はあなたの相互評価後に行われます。Deepthoughtがあなたの作品を採点している間に、あなたの作品のいずれかのセクションでエラーが発生した場合、評価は中断されます。

## Chapter Ⅲ - Mandatory part

1. \
   - [プログラム名] libftprintf.a
   - [ファイル名] Makefile, *.h, */*.h, *.c, */*.c
   - [Makefile] NAME, all, clean, fclean, re
   - [外部関数] malloc, free, write, va_start, va_arg, va_copy, va_end
   - [Libft公認] はい
   - [説明] オリジナルのprintf()を模倣する関数、ft_printf()を含むライブラリを書く。

2. libc の 「printf()」 関数を再コード化する必要があります。
3. 「ft_printf()」のプロトタイプは以下の通りである： 「int ft_printf(const char *, ...);" です。
4. 以下はその要件である：
   - オリジナルのprintf()のバッファ管理は実装しないでください。
   - あなたの関数は以下の変換を処理しなければなりません： 「cspdiuxX%」
   - あなたの関数は、オリジナルのprintf()と比較されます。
   - ライブラリを作成するには、「ar 」コマンドを使用する必要があります。libtool "コマンドの使用は禁止されています。
   - libftprintf.a" は、リポジトリのルートに作成する必要があります。
5. 以下の変換を実装しなければならない：
   - 「%c」 1文字を表示する。
   - 「%s」 文字列を表示する（一般的な C の規約で定義されている）。
   - 「%p」 「void *」 ポインタ引数を 16 進形式で表示します。
   - 「%d」 10進数(基数10)を表示する。
   - 「%i」 10進数の整数を表示します。
   - 「%u」 符号なし 10 進数 (ベース 10) を表示します。
   - 「%x」 16 進数（基数 16）の小文字形式で数値を表示します。
   - 「%X」 16 進数（基数 16）の大文字形式で数値を表示します。
   - 「%%」 パーセント記号を出力します。

## Chapter Ⅳ - Bonus part

1. すべてのボーナスを行う必要はありません。
ボーナスリスト：
   - 以下のフラグの任意の組み合わせを管理する： 「-0.」とすべてのコンバージョンの下のフィールドの最小幅。
   - 以下のすべてのフラグを管理する： 「# +」 (はい、そのうちのひとつはスペースです)

2. ボーナス・パートを完成させるつもりなら、最初から追加機能の実装を考えておくこと。そうすれば、素朴なアプローチの落とし穴を避けることができる。
3. ボーナスパートは、必須パートが完璧である場合にのみ評価されます。完璧とは、必須パートが統合的に行われ、誤動作することなく動作することを意味します。必須条件をすべてクリアしていない場合、ボーナス・パートはまったく評価されません。

## メモ

- %[flags][width][.precision][size]type
  - flags
    - 「-」
    - 「+」
    - 「0」
    - 「 」
    - 「#」
  - width
    - 出力される最小文字数を正の整数で指定
  - .precision
    - 「.」精度指定
      - 文字列 : 表示する最大文字数を指定できる
      - 整数 : 指定した桁数に満たない場合はゼロで埋められる
      - 浮動小数点数(今回は使用しない)
  - size
    - 今回は使用しない
      - 「h」  short, unsigned short
      - 「l」  long, unsigned long
      - 「ll」 long long, unsigned long long
      - 「L」  long double
  - type
    - 「c」 int引数がunsigned charに変換されて出力
    - 「s」 char *引数が文字列の配列を指すポインタとみなされる
    - 「p」 void *引数がアドレスを16進数で出力
    - 「d」 int,short引数を10進数で出力
    - 「i」 int,short引数を10進数で出力(%dと同じ意味)
    - 「u」 unsigned int,unsigned short引数を10進数で出力
    - 「x」 int,short,unsigned int,unsigned shortを16進数で出力(小文字)
    - 「X」 int,short,unsigned int,unsigned shortを16進数で出力(大文字)
    - 「%」 パーセント記号を出力します。

- 可変長引数関数向けの機能
  - va_start
    - void va_start(va_list arg_ptr, prev_param);
    - マクロ関数
    - 可変長引数関数の引数にアクセスできるようにする
  - va_arg
    - type va_arg(va_list arg_ptr, type);
    - マクロ関数
    - 可変長引数関数の次の引数にアクセスする
  - va_copy
    - void va_copy(va_list dest, va_list src);
    - マクロ関数
    - 可変長引数関数の引数をコピーする
  - va_end
    - void va_end(va_list arg_ptr);
    - マクロ関数
    - 可変長引数関数の引数の巡回を終了する
  - va_list
    - 構造体
    - 可変長引数の情報を保存するデータ型

- %[flags][width][.precision][size]type
- printfフォーマット指定市の優先順位
  1. [%] : 開始文字
     - printf関数のフォーマット指定子の開始を示す
  2. ([size] : サイズ修飾子)
     - (後に続くtype(数値のみ)のサイズを決定する)
  3. [type] : 型指定子
     - 出力するデータの型を決定する
     - sizeと組み合わせて解釈される
     - これによってprecisionやwidthの解釈が変わる
       - [c] : 文字
       - [s] : 文字列
       - [p] : ポインタ
       - [d] : 符号あり10進数整数
       - [i] : 符号あり10進数整数
       - [u] : 符号なし10進数整数
       - [x] : 16進数整数(小文字)
       - [X] : 16進数整数(大文字)
       - [%] : パーセント
  4. [.precision] : 精度
     - 表示する最大文字数を指定する(文字列:%s)
     - 表示する最低桁数を指定し、桁数が足りない場合はゼロで埋められる(整数:%d/%i/%u/%x/%X)
     - [.] :
       - [(char *)] :
       - [(int)] :
  5. [width] : フィールド幅
     - precisionで決定された内容の上に、全体のフィールド幅を設定する
     - 幅が不足する場合は、空白で埋められる
     - precisionの後に解釈されるが、flagsよりも優先度が高い
       - [(int)] :
  6. [flags] : フラグ
     - 表示形式を変更する
     - もっとも優先度が低く、ほかの指定が処理された後に適用される
     - 0フラグはprecisionの指定がある場合は無視される
       - [-] : 左寄せ(デフォルトは右寄せ)
       - [+] : 符号出力あり(デフォルトは符号出力なし)
       - [0] : ゼロ埋めあり(デフォルトはゼロ埋めなし、precisionがある場合は無効)
       - [ ] : 空白埋めあり(デフォルトは空白埋めなし)
       - [#] : 16進数(%X/%x)に「0X」「0x」の接頭辞を付ける(その他:無効)

## 参考サイト

- [C言語の可変長引数の関数の作り方](https://qiita.com/subaruf/items/657c67a1809515589a7c "C言語の可変長引数の関数の作り方")
- [va_listってなんだ](https://qiita.com/nori26/items/9ccef61571602a6a3b45 "va_listってなんだ")
- [printfについてまとめてみた](https://zenn.dev/hosu/articles/54022040cb64c8 "printfについてまとめてみた")
- [書式指定構文: printf および wprintf 関数](https://learn.microsoft.com/ja-jp/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-170 "書式指定構文: printf および wprintf 関数")
