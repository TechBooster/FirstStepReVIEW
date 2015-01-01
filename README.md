「はじめてのReVIEW」のレポジトリにようこそ

# これなに

TechBoosterによる『C85 ReVIEW』のメイン作業レポジトリです。
このたび書籍制作ツールRe:VIEWの普及のため、無償公開しました。

# 電子書籍版「はじめてのReVIEW」
https://techbooster.booth.pm/ にて販売中です（このレポジトリからPDFを作っても同等のPDFが仕上がりますが、再配布はご遠慮ください）。

公開後も著作権は保持します。個人利用は問題ありませんがライセンスについては検討中です。
商用利用は控えてください。「Re:VIEWを勉強するために読んで創作活動に活かす」ような使い方を意図しています。

# ファイル構成
原稿は articles/ したに置きます。

たとえば mhidaka さんの場合は
本文を articles/mhidaka.re に、本文から参照している画像を articles/images/mhidaka-hoge.png のように置いてください。大切なことは、本文の .re の前と画像ファイルの先頭が一致することです。

article/CHAPS ファイルに書籍の章番号の順に 原稿ファイルのファイル名が列挙されています。新たに原稿ファイルを追加した際はこのファイルの末尾に追加した原稿のファイル名を追加してください。

# コンパイルしたい

article ディレクトリでコンパイルのためのコマンドを実行します。

## 自分の原稿をhtml化

    review-compile --target=html mhidaka.re > mhidaka.html

もしくは 

    rake clean html re=mhidaka.html

で mhidaka.html が生成されます。

## 全員の原稿を html 化

    rake clean html_all

で *.re に対して *.html が生成されます。

## 全員の原稿を pdf 化

pdf を生成する場合は TeX のインストールが必須です。

    rake clean 
    rake

で book.pdf が出来ます(1行ですませたい場合は `rake clean pdf`)。

中では

    rm -f book.pdf
    rm -rf book/
    review-pdfmaker config.yml

のようなことしているらしいです(rake が使えない場合はこっち？)。

## Debian (wheezy) の場合の環境構築 (おまけ)

* rake, gem, ptex-bin, texlive-fonts-recommended パッケージを入れてください
* sudo gem install review してください
* ほのぼの rake
  * `rake -T` で利用可能なビルドが確認できるよ

## Mac の場合

* sudo gem install review で ReVIEW をインストール
* http://tug.org/mactex/ から MacTeX.pkg をダウンロードしてインストール(pdf生成をしない場合は不要です)
