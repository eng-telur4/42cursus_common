# Libft

## Chapter Ⅰ - Introduction

C programming can be very tedious when one doesn’t have access to the highly useful standard functions. This project is about understanding the way these functions work, implementing and learning to use them. Your will create your own library. It will be helpful since you will use it in your next C school assignments.

Take the time to expand your libft throughout the year. However, when working on a new project, don’t forget to ensure the functions used in your library are allowed in the project guidelines.

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
   - [Prototype] char *get_next_line(int fd);
   - [Turn in files] Makefile, libft.h, ft_*.c
   - [Makefile] NAME, all, clean, fclean, re
   - [External functs.] Detailed below
   - [Libft authorized] n/a
   - [Desctiption] Write your own library: a collection of functions that will be a useful tool for your cursus.
2. Techinical considerations
   - Declaring global variables is forbidden.
   - If you need helper functions to split a more complex function, define them as "static" functions. This way, their scope will be limited to the appropriate file.
   - Place all your files at the root of your repository.
   - Turning in unused files is forbidden.
   - Every .c files must compile with the flags "-Wall -Wextra -Werror".
   - You must use the command "ar" to create your library. Using the "libtool" command is forbidden.
   - Your "libft.a" has to be created at the root of your repository.
3. Libc functions
To begin, you must redo a set of functions from the "libc". Your functions will have the
same prototypes and implement the same behaviors as the originals. They must comply
with the way they are defined in their "man". The only difference will be their names. They
will begin with the ’"ft_"’ prefix. For instance, "strlen" becomes "ft_strlen".
4. Some of the functions’ prototypes you have to redo use the ’restrict’ qualifier. This keyword is part of the c99 standard. It is therefore forbidden to include it in your own prototypes and to compile your code with the -std=c99 flag.
5. You must write your own function implementing the following original ones. They do not require any external functions:
   - isalpha
   - isdigit
   - isalnum
   - isascii
   - isprint
   - strlen
   - memset
   - bzero
   - memcpy
   - memmove
   - strlcpy
   - strlcat
   - toupper
   - tolower
   - strchr
   - strrchr
   - strncmp
   - memchr
   - memcmp
   - strnstr
   - atoi
6. In order to implement the two following functions, you will use "malloc()":
   - calloc
   - strdup
7. Additional functions
In this second part, you must develop a set of functions that are either not in the libc, or that are part of it but in a different form.
8. Some of the following functions can be useful for writing the functions of Part 1.

## Chapter Ⅳ - Bonus part

1. If you completed the mandatory part, do not hesitate to go further by doing this extra one. It will bring bonus points if passed successfully.
2. Functions to manipulate memory and strings is very useful. But you will soon discover that manipulating lists is even more useful.
3. You have to use the following structure to represent a node of your list. Add its declaration to your libft.h file:
4. The members of the t_list struct are:
   - "content": The data contained in the node. "void *" allows to store any kind of data.
   - "next": The address of the next node, or NULL if the next node is the last one.
5. In your Makefile, add a "make bonus" rule to add the bonus functions to your "libft.a".
6. The bonus part will only be assessed if the mandatory part is PERFECT. Perfect means the mandatory part has been integrally done and works without malfunctioning. If you have not passed ALL the mandatory requirements, your bonus part will not be evaluated at all.
7. Implement the following functions in order to easily use your lists.

# Libft

## Chapter Ⅰ - Introduction

C言語のプログラミングは、非常に便利な標準関数にアクセスできないと、非常に退屈なものになる。C言語プログラミングは非常に退屈なものである。このプロジェクトは、これらの関数がどのように機能するかを理解すること、 実装し、その使い方を学ぶものです。あなた自身のライブラリを作成します。それは 次の C スクールの課題でも使うことになるので、役に立ちます。

年間を通して、時間をかけて自分のライブラリを拡張してください。ただし ただし、新しいプロジェクトに取り組むときは、自分のライブラリで使用されている関数がプロジェクトのガイドラインで許可されているかどうかを確認することを忘れないでください。プロジェクトのガイドラインで許可されていることを確認してください。

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
   - [Prototype] char *get_next_line(int fd);
   - [Turn in files] Makefile, libft.h, ft_*.c
   - [Makefile] NAME, all, clean, fclean, re
   - [External functs.] Detailed below
   - [Libft authorized] n/a
   - [Desctiption] 独自のライブラリを作成する：カーサスの便利なツールとなる関数のコレクション。
2. 技術的考察
   - グローバル変数の宣言は禁止されている。
   - より複雑な関数を分割するためにヘルパー関数が必要な場合は、「static 」関数として定義してください。こうすることで、スコープが適切なファイルに限定されます。
   - すべてのファイルをリポジトリのルートに置いてください。
   - 未使用のファイルを置くことは禁止されています。
   - すべての .c ファイルは、「-Wall -Wextra -Werror 」フラグを付けてコンパイルしなければならない。
   - ライブラリを作成するには、「ar 」コマンドを使用しなければなりません。libtool "コマンドの使用は禁止されています。
   - libft.a" はリポジトリのルートに作成しなければならない。
3. Libc 関数
まず、「libc」 から関数のセットを作り直さなければなりません。あなたの関数は
同じプロトタイプを持ち、オリジナルと同じ動作を実装します。これらの関数は
man "で定義されている方法に従わなければならない。唯一の違いは名前です。それらは
ft_"」という接頭辞で始まる。例えば、「strlen 」は 「ft_strlen 」となる。
4. やり直さなければならない関数のプロトタイプの中には、'restrict'修飾子を使っているものがある。このキーワードはc99標準の一部である。したがって、このキーワードを自分自身のプロトタイプに含めたり、 -std=c99フラグを付けてコードをコンパイルすることは禁止されている。
5. 以下のオリジナル関数を実装した独自の関数を書かなければならない。これらは外部関数を必要としません：
   - isalpha
   - isdigit
   - isalnum
   - isascii
   - isprint
   - strlen
   - memset
   - bzero
   - memcpy
   - memmove
   - strlcpy
   - strlcat
   - toupper
   - tolower
   - strchr
   - strrchr
   - strncmp
   - memchr
   - memcmp
   - strnstr
   - atoi
6. 以下の2つの関数を実装するには、「malloc()」を使用する：
   - calloc
   - strdup
7. 追加機能
この第2部では、libcにない、あるいはlibcの一部ではあるが別の形になっている関数のセットを開発しなければならない。
8. 以下の関数のいくつかは、パート1の関数を書くのに役立つ。

## Chapter Ⅳ - Bonus part

1. 必須パートを終えたなら、迷わずこの追加パートに挑戦しよう。合格すればボーナスポイントが加算される。
2. メモリや文字列を操作する関数はとても便利です。しかし、リストを操作することはもっと便利であることがすぐにわかるだろう。
3. リストのノードを表すには、以下の構造体を使わなければなりません。その宣言をlibft.hファイルに追加してください：
4. t_list構造体のメンバーは以下の通り：
   - content"： ノードに含まれるデータ。「void *」は任意のデータを格納できる。
   - 「next」：次のノードのアドレス： 次のノードのアドレス、または次のノードが最後のノードの場合はNULL。
5. 5.Makefileに 「make bonus 」ルールを追加して、ボーナス関数を 「libft.a 」に追加する。
6. 6.ボーナス部分は、必須部分がPERFECTの場合のみ評価されます。パーフェクトとは、必須部分が統合的に行われ、誤動作することなく動作することを意味します。必須項目をすべてクリアしていない場合、ボーナス部分はまったく評価されません。
7. 7.リストを使いやすくするために、以下の機能を実装してください。

## 参考サイト

- [【C言語】配列をコピーするmemcpy / memmoveやstrcpyとの違い](https://hikotech.net/post-100/ "【C言語】配列をコピーするmemcpy / memmoveやstrcpyとの違い")
