# get_next_line

## Chapter Ⅰ - Goals

This projet will not only allow yout ot add a very convenient function to your collection, but it will also make you learn a highly interesting new concept in C programming: static variavles.

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
   - [Function name] get_next_line
   - [Prototype] char *get_next_line(int fd);
   - [Turn in files] get_next_line.c, get_next_line_utils.c, get_nect_line.h
   - [Parameters] fd: The file discriptor to read from
   - [Return Value]
     - Read line: correct behavior
     - NULL: there is nothing else to read, or an error occurred
   - [External functs.] read, malloc, free
   - [Desctiption] Write a function that returns a line read from a file descriptor
2. \
   - Repeated calls (e.g., using a loop) to your "get_next_line()" function should let you read the text file pointed to by the file desctiptor, "one line at a time".
   - Your function should return the line that was read. If there is nothing else to read or if an error occurred, it should return NULL.
   - Make sure that your function works as expected both when reading a file and then reading from the standard input.
   - "Please note" that the returned line should include the terminating "\n" character, except if the end of file was reached and does not end with a "\n" character.
   - Your header file "get_next_line.h" must at least contain the prototyoe of the "get_next_line()" function.
   - Add all the helper functions you need in the "get_next_line_utils.c" file.
3. A good start would be to know what a "static variable" is.
4. \
   - Because you will have to read files in "get_next_line()", add this option to your compiler call: "-D BUFFER_SIZE=\n". It will define the buffer size for "read()". The buffer size value will be modified by your peer-evaluators and the Moulinette in order to test your code.
5. We must be able to compile this project with and without the -D BUFFER_SIZE flag in addition to the usual flags. You can choose the default value of your choice.
6. \
   - You will compile your code as follows (a buffer size of 42 is used as an example): "cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \<files\>.c".
   - We consider that "get_next_line()" has an undefined behavior if the file pointed to by the file descriptor changed since the last call whereas "read()" didn't reach the end of file.
   - We also consifer that "get_next_line()" has an undefined behavior when reading a binary file. However, you can implement a logical way to handle this behavior if you want to.
7. Does your function still work if the BUFFER_SIZE value is 9999? If it is 1? 10000000? Do you know why?
8. Try to read as little as possible each time get_next_line() is called. If you encounter a new line, you have to return the current line. Don't read the whole file and then process each line.
9. "Forbidden"
   - You are not allowed to use your "libft" in this project.
   - "lseek()" is forbidden.
   - Global variables are forbidden.

## Chapter Ⅳ - Bonus part

This project is straightforward and doesn't allow complex bonuses. However, we trust your creativity. If you completed he mandatory part, give a try to this bonus part.
Here are the bonus part requirements:
- Develop "get_next_line()" using only on static valiable
- Your "get_next_line()" can manage multiple file descriptors at the same time. For example, if you can read from the file descriptors 3, 4 and 5, you should be able to read from a different fd per call without losing the reading thread of each file descriptor or returning a line from another fd. It means that you should be able to call "get_next_line()" to read from fd 3, then fd 4, then 5, then once again 3, on again 4, and so forth.
Append the _bonus.[c/h] suffix to the bonus part files.
It means that, in addition to the mandatory part files, you will turn in the 3 following files:
- "get_next_line_bonus.c"
- "get_next_line_bonus.h"
- "get_next_line_utils_bonus.c"

The bonus part will only be assessed if the mandatory part is PERFECT. Perfect means the mandatory part has been integrally done and works without malfunctioning. If you have not passed ALL the mandatory requirements, your bonus part will not be evaluated at all.

# get_next_line

## Chapter Ⅰ - Goals

このプロジェクトは、あなたのコレクションにとても便利な関数を追加することを可能にするだけでなく、C言語プログラミングにおける非常に興味深い新しい概念、静的変数についても学ばせてくれるだろう。

## Chapter Ⅱ - Common Instructions

- [ ] あなたのプロジェクトはC言語で書かれていなければなりません；
- [ ] あなたのプロジェクトは規範に従って書かれていなければなりません。ボーナスファイル/関数がある場合、それらは規範チェックに含まれ、内部に規範エラーがある場合は0が返されます。
- [ ] あなたの関数は、未定義の動作とは別に、予期せぬ終了（sefmentation fault、bus error、double freeなど）をしてはいけません。このような場合、プロジェクトは非機能とみなされ、評価中に0が返されます。
- [ ] ヒープに割り当てられたすべてのメモリ空間は、必要なときに適切に解放されなければなりません。ループは許されません。
- [ ] 課題によって必要な場合は、ソースファイルを必要な出力にコンパイルする「Makefile」を、「-Wall」、「-Wextra」、「-Werror」のフラグ付きで提出しなければなりません。
- [ ] Makefile には、少なくとも 「$(NAME)」、「all」、「clean」、「fclean」、「re」 というルールが含まれていなければなりません。
- [ ] プロジェクトにボーナスを追加するには、Makefile に 「bonus」 というルールを追加する必要があります。このルールは、プロジェクトのメインパートで禁止されている、さまざまなヘッダー、ライブラリ、関数をすべて追加します。ボーナスは、対象が他に何も指定しない場合は、別のファイル 「_bonus.{c/h}」 にする必要があります。必須パートとボーナスパートの評価は別々に行われます。
- [ ] あなたのプロジェクトで libft を使用できる場合は、そのソースと関連する 「Makefile」 を 「libft」 フォルダに関連する Makefile と一緒にコピーする必要があります。プロジェクトの 「Makefile 」は、「Makefile 」を使用してライブラリをコンパイルし、プロジェクトをコンパイルしなければなりません。
- [ ] この作業は「提出する必要はなく、採点もされません」が、プロジェクトのテストプログラムを作成することをお勧めします。自分の作品や仲間の作品を簡単にテストすることができます。このようなテストは、ディフェンスの際に特に役立ちます。実際、ディフェンスの際には、自分のテストや評価する仲間のテストを自由に使用することができます。
- [ ] 自分の作品を指定された git リポジトリに提出してください。git リポジトリにある作品のみが採点されます。Deepthought があなたの作品の採点を担当することになった場合、採点はあなたの相互評価後に行われます。Deepthoughtがあなたの作品を採点している間に、あなたの作品のいずれかのセクションでエラーが発生した場合、評価は中断されます。

## Chapter Ⅲ - Mandatory part

1. \
   - [x] [関数名] get_next_line
   - [x] [プロトタイプ] char *get_next_line(int fd)；
   - [x] [ファイル名] get_next_line.c, get_next_line_utils.c, get_nect_line.h
   - [x] [パラメータ] fd： 読み込むファイルディスクリプタ
   - [ ] [戻り値]
     - Read line: 正しい動作
     - NULL: 他に読み込むものがないか、エラーが発生した。
   - [ ] [外部関数] read, malloc, free
   - [ ] [説明] ファイルディスクリプタから読み込んだ行を返す関数を書きなさい。

2. \
   - [ ] 「get_next_line()」関数を繰り返し呼び出す（ループを使うなど）ことで、 ファイル記述子が指すテキストファイルを「一度に一行ずつ」読めるようにしなさい。
   - [ ] 関数は、読み込まれた行を返すはずです。他に読み込むものがない場合やエラーが発生した場合は、NULLを返すべきです。
   - [ ] ファイルを読み込むときも、標準入力から読み込むときも、関数が期待通りに動作することを確認してください。
   - [ ] 「ファイルの末尾」に到達し、「\n 」文字で終わらない場合を除き、返される行には「\n 」文字が含まれることに注意してください。
   - [x] ヘッダーファイル 「get_next_line.h 」には、少なくとも 「get_next_line() 」関数のプロトタイプが含まれていなければなりません。
   - [ ] get_next_line_utils.c "ファイルに必要なヘルパー関数をすべて追加する。
3. [x] 静的変数 "が何であるかを知ることが良いスタートとなるだろう。
4. \
   - [ ] 「get_next_line()」でファイルを読み込む必要があるので、コンパイラの呼び出しに次のオプションを追加する： 「BUFFER_SIZE=n" を追加する。これは、「read() 」のバッファ・サイズを定義する。バッファ・サイズの値は、あなたのコードをテストするために、あなたのピア・エバリュエータとMoulinetteによって変更される。
5. [ ] 通常のフラグに加えて、-D BUFFER_SIZEフラグの有無にかかわらず、このプロジェクトをコンパイルできなければならない。デフォルト値はお好みで選んでください。
6. \
   - [ ] 以下のようにコードをコンパイルします（例としてバッファサイズ42を使用）： 「cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \<files\>.c」.
   - [ ] get_next_line()は、read()がファイル末尾に到達していないとき、ファイル記述子が指 すファイルが最後に呼び出されたときから変更されている場合、未定義の動作をすると考 えられる。
   - [ ] また、「get_next_line()」 は、バイナリ・ファイルを読み込むときにも未定義の動作をする。しかし、必要であれば、この動作を処理する論理的な方法を実装することができる。
7. [ ] BUFFER_SIZE の値が 9999 の場合でも、この関数は動作しますか？BUFFER_SIZEが1? 10000000? なぜかわかりますか？
8. [ ] get_next_line()が呼び出されるたびに、できるだけ読み込まないようにしてください。改行があったら、現在の行を返さなければならない。ファイル全体を読んでから各行を処理するのはやめましょう。
9. [ ] 「禁止」
   - [ ] このプロジェクトでは、「libft 」の使用は禁止されている。
   - [ ] lseek()は禁止されています。
   - [ ] グローバル変数の使用は禁止されています。

## Chapter Ⅳ - Bonus part

このプロジェクトはシンプルで、複雑なボーナスは認められていません。しかし、私たちはあなたの創造性を信頼しています。必須パートをクリアしたら、このボーナス・パートに挑戦してみよう。
以下がボーナスパートの条件です：
- 「get_next_line() 」を一つの静的変数のみを使って開発すること。
- あなたの 「get_next_line() 」は、複数のファイル記述子を同時に管理できる。例えば、ファイル・ディスクリプタ3、4、5から読み込むことができれば、各ファイル・ディスクリプタの読み込みスレッドを失うことなく、また別のfdから行を返すことなく、呼び出しごとに異なるfdから読み込むことができるはずである。つまり、「get_next_line() 」を呼び出してfd 3から読み込み、次にfd 4から読み込み、次に5から読み込み、もう一度3から読み込み、また4から読み込み......といったことができるはずである。
ボーナス・パート・ファイルに接尾辞_bonus.[c/h]をつける。
これは、必須パートファイルに加えて、以下の3つのファイルを提出することを意味する：
- 「get_next_line_bonus.c」
- 「get_next_line_bonus.h」
- 「get_next_line_utils_bonus.c」

ボーナス部分は、必須部分がパーフェクトである場合にのみ評価される。パーフェクトとは、必須部分が統合的に行われ、誤動作することなく動作することを意味する。もし必須条件をすべてクリアしていなければ、ボーナス部分はまったく評価されません。
