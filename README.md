# 乱数の演習

# 進め方
## はじめてのとき
* [GitHub](https://github.com/)のアカウントを作成してください
* [Travis CI](https://travis-ci.org/) のアカウントを作成してください
* GitHubのアカウントを[こちらのフォーム](https://goo.gl/forms/anAdoxqPKVt8sJGZ2)から教えてください。
## 毎回の進め方
* このリポジトリをforkしてください
* Travis CI を設定して、自動ビルドが通るようにしてください
   * Travis CI のGitHubアカウントでの登録とforkしたリポジトリをTravisCI側で許可する
   * 参考サイト：[Travis CI入門 Travis CIとGitHubでCIを実現する方法(Change the World!)](http://changesworlds.com/2014/09/introduction-to-travis-ci-and-github-001/)
* forkしたリポジトリの README.md ファイルの「t-kougei-game-comp」の部分を自分のGitHubアカウント名に差し替えてください(2箇所)
* 問題を解いて、テストを通るようにしてください。
* fork 元の master ブランチにプルリクエストを投げてください

# テスト結果

[![Build Status](https://travis-ci.org/t-kougei-game-comp/rand.svg?branch=master)](https://travis-ci.org/t-kougei-game-comp/rand)

# 今回の問題

乱数の勉強です。

線形合同法で乱数を生成してください。

input?.txt ファイルを標準入力として読み込んで、標準出力の結果を output?.txt ファイルと一致するか比較するテストをします。

main.c ファイルだけを書き換えて下さい。

## 入力される値
入力は以下のフォーマットで与えられます。
~~~
seed
max
num
~~~

* seed: 乱数の初期値
* max: 生成する乱数の最大値
* num: 生成する乱数の数

## 期待する出力

乱数を「num」個生成して、各行に出力してください。

乱数は、「x=(48271*x) mod (2^31 - 1)」のPark & Millerの式で生成してください。xの初期値は「seed」となります。

生成した乱数xから、x/(0xfffffffe/max+1)+1の式を使って、[1,max]の範囲に変換して出力してください。

最後は改行し、余計な文字、空行を含んではいけません。

## 条件
すべてのテストケースで数字は以下の条件を満たします。
* 0 <= seed <= 0xffffffff
* 1 <= max <= 1000
* 1 <= num <= 1000

## 入力例1
~~~
1
0xffffffff
1
~~~
* seedが「1」なので、x=48271になります
* maxが「0xffffffff」なので、、x/(0xfffffffe/max+1)+1=48271+1=48272になります
* numが「1」なので、乱数を１つ出力して終了します

## 出力例1
~~~
48272
~~~

## 入力例2
~~~
1
6
10
~~~

## 出力例1
~~~
1
4
5
1
2
6
4
4
2
1
~~~
