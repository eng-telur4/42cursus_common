# push_swap

## Chapter Ⅰ - Foreword

## Chapter Ⅱ - Introduction

- The Push swap project is a very simple and a highly straightforward algorithm project: data must be sorted.
- You have at your disposal a set of integer values, 2 stacks, and a set of instructions to manipulate both stacks.
- Your goal? Write a program in C called push_swap which calculates and displays on the standard output the smallest program, made of Push swap language instructions, that sorts the integers received as arguments.
- Easy?
- We’ll see...

## Chapter Ⅲ - Objectives

- Writing a sorting algorithm is always a very important step in a developer’s journey. It is often the first encounter with the concept of complexity.
- Sorting algorithms and their complexity are part of the classic questions discussed during job interviews. It’s probably a good time to look at these concepts since you’ll have to face them at some point.
- The learning objectives of this project are rigor, use of C, and use of basic algorithms. Especially focusing on their complexity.
- Sorting values is simple. To sort them the fastest way possible is less simple. Especially because from one integers configuration to another, the most efficient sorting solution can differ.

## Chapter Ⅳ - Common Instruction

- Your project must be written in C.
- Your project must be written in accordance with the Norm. If you have bonus files/functions, they are included in the norm check and you will receive a 0 if there is a norm error inside.
- Your functions should not quit unexpectedly (segmentation fault, bus error, double free, etc) apart from undefined behaviors. If this happens, your project will be considered non functional and will receive a 0 during the evaluation.
- All heap allocated memory space must be properly freed when necessary. No leaks will be tolerated.
- If the subject requires it, you must submit a Makefile which will compile your source files to the required output with the flags -Wall, -Wextra and -Werror, use cc, and your Makefile must not relink.
- Your Makefile must at least contain the rules $(NAME), all, clean, fclean and re.
- To turn in bonuses to your project, you must include a rule bonus to your Makefile, which will add all the various headers, libraries or functions that are forbidden on the main part of the project. Bonuses must be in a different file _bonus.{c/h} if the subject does not specify anything else. Mandatory and bonus part evaluation is done separately.
- If your project allows you to use your libft, you must copy its sources and its associated Makefile in a libft folder with its associated Makefile. Your project’s Makefile must compile the library by using its Makefile, then compile the project.
- We encourage you to create test programs for your project even though this work won’t have to be submitted and won’t be graded. It will give you a chance to easily test your work and your peers’ work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating.
- Submit your work to your assigned git repository. Only the work in the git repository will be graded. If Deepthought is assigned to grade your work, it will be done after your peer-evaluations. If an error happens in any section of your work during Deepthought’s grading, the evaluation will stop.

## Chapter Ⅴ - Mandatory part

1. The rules
   - You have 2 stacks named a and b.
   - At the beginning:
     - The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
     - The stack b is empty.
   - The goal is to sort in ascending order numbers into stack a. To do so you have the	following operations at your disposal:
     - ```sa (swap a)```: Swap the first 2 elements at the top of stack a.\
Do nothing if there is only one or no elements.
     - ```sb (swap b)```: Swap the first 2 elements at the top of stack b.\
Do nothing if there is only one or no elements.
     - ```ss``` : sa and sb at the same time.
     - ```pa (push a)```: Take the first element at the top of b and put it at the top of a.\
Do nothing if b is empty.
     - ```pb (push b)```: Take the first element at the top of a and put it at the top of b.\
Do nothing if a is empty.
     - ```ra (rotate a)```: Shift up all elements of stack a by 1.\
The first element becomes the last one.
     - ```rb (rotate b)```: Shift up all elements of stack b by 1.\
The first element becomes the last one.
     - ```rr``` : ra and rb at the same time.
     - ```rra (reverse rotate a)```: Shift down all elements of stack a by 1.\
The last element becomes the first one.
     - ```rrb (reverse rotate b)```: Shift down all elements of stack b by 1.\
The last element becomes the first one.
     - ```rrr``` : rra and rrb at the same time.

2. Example

To illustrate the effect of some of these instructions, let’s sort a random list of integers.
In this example, we’ll consider that both stacks grow from the right.
Integers from a get sorted in 12 instructions. Can you do better?

3. The "push_swap" program

   - [Program name] push_swap
   - [Turn in files] Makefile, *.h, *.c
   - [Makefile] NAME, all, clean, fclean, re
   - [Arguments] stack a: A list of integers
   - [External functs.]
     - read, write, malloc, free, exit
     - ft_printf and any equivalent YOU coded
   - [Libft authorized] Yes
   - [Description] Sort stacks

Your project must comply with the following rules:
- You have to turn in a Makefile which will compile your source files. It must not relink.
- Global variables are forbidden.
- You have to write a program named push_swap that takes as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order).
- The program must display the smallest list of instructions possible to sort the stack a, the smallest number being at the top.
- Instructions must be separated by a ’\n’ and nothing else.
- The goal is to sort the stack with the lowest possible number of operations. During the evaluation process, the number of instructions found by your program will be compared against a limit: the maximum number of operations tolerated. If your program either displays a longer list or if the numbers aren’t sorted properly, your grade will be 0.
- If no parameters are specified, the program must not display anything and give the prompt back.
- In case of error, it must display "Error" followed by a ’\n’ on the standard error. Errors include for example: some arguments aren’t integers, some arguments are bigger than an integer and/or there are duplicates.

During the evaluation process, a binary will be provided in order to properly check your program.\
It will work as follows:\
If the program checker_OS displays "KO", it means that your push_swap came up with a list of instructions that doesn’t sort the numbers.\

The checker_OS program is available in the resources of the project in the intranet.\
You can find a description of how it works in the Bonus Part of this document.

4. Benchmark

To validate this project, you must perform certain sorts with a minimal number of operations:
- For a minimalist validation (that implies a minimal grade of 80), you must be able to sort 100 random numbers in fewer than 700 operations.
- For maximal project validation and thus to be able to achieve the bonuses, you must fulfill the first step above, but also for 500 random numbers, there should be no more than 5500 operations.
All of this will be verified during your evaluation.\

If you wish to complete the bonus part, you must thoroughly validate the project with each benchmark step achieving the highest possible score.

## Chapter Ⅵ - Bonus part

This project leaves little room for adding extra features due to its simplicity. However, how about creating your own checker?

Thanks to the checker program, you will be able to check whether the list of instructions generated by the push_swap program actually sorts the stack properly.

The bonus part will only be assessed if the mandatory part is PERFECT. Perfect means the mandatory part has been integrally done and works without malfunctioning.In this project, this entails validating all benchmarks without exception. If you have not passed ALL the mandatory requirements, your bonus part will not be evaluated at all.

1. The "checker" program
   - [Progra name] checker
   - [Turn in files] *.h, *.c
   - [Makefile] bonus
   - [Arguments] stack a: A list of integers
   - [External functs.]
     - read, write, malloc, free, exit
     - ft_printf and any equivalent YOU coded
   - [Libft authorized] Yes
   - [Description] Execute the sorting instructions

- Write a program named checker that takes as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order). If no argument is given, it stops and displays nothing.
- It will then wait and read instructions on the standard input, each instruction will be followed by ’\n’. Once all the instructions have been read, the program has to execute them on the stack received as an argument.
- If after executing those instructions, the stack a is actually sorted and the stack b is empty, then the program must display "OK" followed by a ’\n’ on the standard output.
- In every other case, it must display "KO" followed by a ’\n’ on the standard output.
- In case of error, you must display "Error" followed by a ’\n’ on the standard error. Errors include for example: some arguments are not integers, some arguments are bigger than an integer, there are duplicates, an instruction doesn’t exist and/or is incorrectly formatted.

You DO NOT have to reproduce the exact same behavior as the provided binary. It is mandatory to manage errors but it is up to you to decide how you want to parse the arguments.

The bonus part will only be assessed if the mandatory part is PERFECT. Perfect means the mandatory part has been integrally done and works without malfunctioning.In this project, this entails validating all benchmarks without exception. If you have not passed ALL the mandatory requirements, your bonus part will not be evaluated at all.

## Chapter Ⅶ - Submission and peer-evaluation

Turn in your assignment in your Git repository as usual. Only the work inside your repository　will be evaluated during the defense. Don’t hesitate to double check the names of　your files to ensure they are correct.

As these assignments are not verified by a program, feel free to organize your files as　you wish, as long as you turn in the mandatory files and comply with the requirements.

file.bfe:VABB7yO9xm7xWXROeASsmsgnY0o0sDMJev7zFHhwQS8mvM8V5xQQpLc6cDCFXDWTiFzZ2H9skYkiJ/DpQtnM/uZ0

# push_swap

## Chapter Ⅰ - Foreword

## Chapter Ⅱ - Introduction

- プッシュ・スワップ（Push swap）プロジェクトは非常に単純で、非常にわかりやすいアルゴリズム・プロジェクトである。
- データをソートしなければならない。自由に使えるのは、整数値のセット、2つのスタック、両方のスタックを操作する命令セットである。
- あなたの目標は？引数として受け取った整数をソートする、Push swap言語命令で作られた最小のプログラムを計算し、標準出力に表示するpush_swapというプログラムをCで書くこと。
- 簡単か？
- 今にわかるよ。

## Chapter Ⅲ - Objectives

- ソート・アルゴリズムを書くことは、開発者にとって常に非常に重要なステップである。多くの場合、複雑さの概念との最初の出会いでもある。
- ソート・アルゴリズムとその複雑性は、就職面接の際に議論される典型的な質問の一部である。いずれは直面することになるだろうから、これらの概念に目を向けるのは良い機会だろう。
- このプロジェクトの学習目標は、厳密さ、C言語の使用、基本的なアルゴリズムの使用である。特にその複雑さに焦点を当てる。
- 値の並べ替えは簡単だ。可能な限り最速の方法でソートすることは、それほど単純ではない。特に、整数の構成によって、最も効率的なソート方法が異なることがあるからだ。

## Chapter Ⅳ - Common Instruction

- あなたのプロジェクトはC言語で書かれていなければなりません。
- あなたのプロジェクトは規範に従って書かれていなければなりません。ボーナスファイル/関数がある場合、それらは規範チェックに含まれ、内部に規範エラーがある場合は0が返されます。
- 関数は、未定義の動作とは別に、予期せぬ終了（セグメンテーションフォールト、バスエラー、ダブルフリーなど）をしてはいけません。このような場合、プロジェクトは非機能とみなされ、評価中に0が返されます。
- ヒープに割り当てられたメモリ空間は、必要なときに適切に解放しなければなりません。リークは許されません。
- 課題によって必要な場合、ソースファイルを必要な出力にコンパイルする Makefile を -Wall、-Wextra、-Werror フラグ付きで提出し、cc を使用し、Makefile を再リンクしてはいけません。
- Makefile には少なくとも $(NAME)、all、clean、fclean、re のルールが含まれていなければなりません。
- プロジェクトにボーナスを投入するには、Makefile にボーナスというルールを追加する必要があります。ボーナスは、プロジェクトのメイン部分で禁止されている様々なヘッダやライブラリ、関数をすべて追加します。ボーナスは、対象が他に何も指定しない場合は、別のファイル _bonus.{c/h} に記述しなければなりません。必須パートとボーナスパートの評価は別々に行われます。
- あなたのプロジェクトで libft を使用できる場合は、そのソースと関連する Makefile を libft フォルダにコピーして、関連する Makefile と一緒にしなければなりません。あなたのプロジェクトの Makefile は、その Makefile を使ってライブラリをコンパイルし、それからプロジェクトをコンパイルしなければなりません。
- この作業は提出する必要はなく、採点もされませんが、 プロジェクトのテストプログラムを作成することをお勧めします。自分の作品や仲間の作品を簡単にテストすることができます。これらのテストは、ディフェンスの際に特に役立ちます。実際、ディフェンスの際には、あなたが作成したテストや、あなたが評価する仲間のテストを自由に使用することができます。
- あなたの作品を指定された git リポジトリに提出してください。git リポジトリにある作品のみが採点されます。Deepthoughtがあなたの作品の採点を担当する場合、採点はあなたの相互評価後に行われます。Deepthoughtがあなたの作品を採点している間に、あなたの作品のいずれかのセクションでエラーが発生した場合、評価は中断されます。

## Chapter Ⅴ - Mandatory part

1. ルール
   - aとbという2つのスタックがある。
   - 最初に
     - スタック a には複製不可能な負の数と正の数がランダムに入る。
     - スタック b は空である。
   - 目標は、スタック a に数字を昇順に並べ替えることである：
     - ```sa (swap a)```： スタックaの先頭の2つの要素を入れ替えます。\
要素が1つしかない場合、または要素がない場合は何もしません。
     - ```sb (swap b)```： スタックbの先頭の2つの要素を入れ替えます。\
要素が1つしかない場合、または要素がない場合は何もしません。
     - ```sb (swap a)``` : sa と sb を同時にスワップします。
     - ```pa (push a)```： bの先頭の要素を取り、aの先頭に置きます。\
bが空の場合は何もしない。
     - ```pb (push b)```： aの先頭の要素を取り、bの先頭に置きます。\
aが空の場合は何もしません。
     - ```ra (rotate a)```： スタックaのすべての要素を1ずつ上にずらします。\
最初の要素が最後の要素になります。
     - ```rb (rotate b)```： スタック b のすべての要素を 1 ずつ上に移動します。\
最初の要素が最後の要素になります。
     - ```rr`` : raとrbを同時に回転させます。
     - ```rra (reverse rotate a)```： スタックaのすべての要素を1つ下にシフトします。\
最後の要素が最初の要素になります。
     - ```rrb (reverse rotate b)```： スタックbのすべての要素を1つシフトダウンします。\
最後の要素が最初の要素になります。
     - ```rrr```: rra と rrb を同時に実行します。

2. 例題

これらの命令の効果を説明するために、整数のランダムなリストをソートしてみよう。
この例では、どちらのスタックも右から成長していくと考える。
aからの整数は12命令でソートされる。もっとうまくできるだろうか？

3. 「push_swap」プログラム

   - [プログラム名] push_swap
   - [ファイル名] Makefile, *.h, *.c
   - [Makefile] NAME, all, clean, fclean, re
   - [引数] stack a： 整数のリスト
   - [外部関数]
     - read, write, malloc, free, exit
     - ft_printfと同等のYOUコード
   - [Libft認証] はい
   - [説明] スタックのソート

あなたのプロジェクトは以下のルールに従わなければなりません：
- ソースファイルをコンパイルする Makefile を提出しなければならない。再リンクしてはいけません。
- グローバル変数は禁止されています。
- あなたは、引数として整数のリストとしてフォーマットされたスタックを受け取る push_swap という名前のプログラムを書かなければなりません。最初の引数はスタックの一番上になければならない（順番に注意）。
- プログラムはスタック a をソートするために可能な限り小さな命令リストを表示しなければならない。
- 命令は「'」で区切らなければならず、それ以外には何も入れてはならない。
- 目標は、可能な限り少ない操作回数でスタックをソートすることである。評価プロセス中、あなたのプログラムが見つけた命令の数は、許容される操作の最大数という制限と比較されます。あなたのプログラムがより長いリストを表示するか、数字が適切にソートされていない場合、あなたの成績は 0 となります。
- パラメータが指定されていない場合、プログラムは何も表示せず、プロンプトを返さなければなりません。
- エラーの場合、標準エラーに 「Error 」の後に' \n'を表示しなければなりません。エラーとは例えば、引数が整数でない、引数が整数より大きい、重複している、などです。

評価プロセスでは、プログラムを適切にチェックするためのバイナリが提供されます。
これは次のように動作します：
もしchecker_OSプログラムが 「KO 」と表示したら、それはあなたのpush_swapが数字を並べ替えていない命令リストを作成したことを意味します。

checker_OSプログラムは、イントラネットのプロジェクトのリソースにあります。
このドキュメントのボーナス・パートに、どのように動作するかの説明があります。

4. ベンチマーク

このプロジェクトを検証するには、最小限の操作回数で特定のソートを実行しなければならない：
- 最小限の検証（最低80点）のためには、100個の乱数を700回以下の操作でソートできなければならない。
- 最大限のプロジェクト検証を行い、ボーナスを獲得するためには、上記の最初のステップを満たすだけでなく、500個の乱数を5500回以下の操作で並べ替える必要があります。
これらはすべて、あなたの評価中に検証されます。

ボーナスパートを達成したい場合は、各ベンチマークステップでプロジェクトを徹底的に検証し、可能な限り高いスコアを達成する必要があります。

## Chapter Ⅵ - Bonus part

このプロジェクトは、そのシンプルさゆえに、余分な機能を追加する余地をほとんど残していない。しかし、あなた自身のチェッカーを作るのはどうだろう？

チェッカー・プログラムのおかげで、push_swapプログラムによって生成された命令リストが実際にスタックを正しくソートしているかどうかをチェックできるようになる。

ボーナス・パートは、必須パートがパーフェクトである場合にのみ評価される。このプロジェクトでは、すべてのベンチマークを例外なく検証することを意味します。このプロジェクトでは、例外なくすべてのベンチマークを検証することを意味します。必須条件をすべてクリアしていない場合、ボーナス・パートはまったく評価されません。

1. 「チェッカー」プログラム
   - [プログラム名] checker
   - [ファイル名] *.h, *.c
   - [Makefile] bonus
   - [引数] stack a： 整数のリスト
   - [外部関数]
     - read, write, malloc, free, exit
     - ft_printfと同等のYOUコード
   - [Libft認証] あり
   - [説明] ソート命令の実行

- 整数のリストとしてフォーマットされたスタックを引数として受け取るcheckerという名前のプログラムを書きなさい。最初の引数はスタックの先頭でなければならない（順番に注意）。引数が与えられない場合は、停止して何も表示しない。
- その後、待機して標準入力の命令を読み込み、各命令の後に'˶n'が続く。すべての命令が読み込まれたら、プログラムは引数として受け取ったスタック上の命令を実行しなければならない。
- これらの命令を実行した後、スタックaが実際にソートされ、スタックbが空であれば、プログラムは標準出力に'˶n'が続く 「OK 」を表示しなければならない。
- それ以外の場合は、標準出力に 「KO 」と'˶n'を表示しなければならない。
- エラーの場合、標準エラーに 「Error 」と'˶n'を表示しなければなりません。エラーとは、例えば、引数が整数でない、引数が整数より大きい、重複がある、命令が存在しない、書式が正しくない、などです。

提供されたバイナリとまったく同じ動作を再現する必要はありません。エラーを管理することは必須ですが、引数をどのように解析するかはあなた次第です。

ボーナスパートは、必須パートが完璧である場合にのみ評価されます。このプロジェクトでは、すべてのベンチマークを例外なく検証することを意味します。このプロジェクトでは、例外なくすべてのベンチマークを検証することを意味します。必須条件をすべてクリアしていない場合、ボーナス・パートはまったく評価されません。

## Chapter Ⅶ - Submission and peer-evaluation

通常通り、Gitリポジトリに課題を提出してください。あなたのリポジトリ内の作品だけが、ディフェンス中に評価されます。ファイル名が正しいかどうか、ためらわずにダブルチェックしてください。

これらの課題はプログラムによって検証されるわけではないので、必須ファイルを提出し、要件を遵守している限り、自由にファイルを整理してください。

file.bfe:VABB7yO9xm7xWXROeASsmsgnY0o0sDMJev7zFHhwQS8mvM8V5xQpLc6cDCFXDWTiFzZ2H9skYkiJ/DpQtnM/uZ0

### メモ

- スタックaとbがある
- 最初はaに数値が入っている
- 最終目標は、aに入った数値を昇順にソートすること

```
+--------a--------+--------b--------+
|[  2]3           |                 |
|[  0]1           |                 |
|[  1]2           |                 |
+-----------------+-----------------+
こうしたい
+--------a--------+--------b--------+
|[  0]1           |                 |
|[  1]2           |                 |
|[  2]3           |                 |
+-----------------+-----------------+
```

### 参考サイト

- [push_swap | Guide - GitBook](https://42-cursus.gitbook.io/guide/rank-02/push_swap "push_swap | Guide - GitBook")
