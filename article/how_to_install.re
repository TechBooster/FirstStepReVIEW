= 環境構築

//lead{
本章では、ReVIEWで原稿を執筆する環境の構成と、その構築方法を紹介します。
//}
#@# レビュー by わかめ ReVIEWによる原稿を執筆する環境の構成と、その構築方法を紹介します。 とかのほうが好き。
#@# それ採用

== ReVIEW環境の構成

@<chap>{introduction}でも述べたとおり、本書において「ReVIEW」とは、書籍の出版に適したテキストベースの軽量マークアップ言語「ReVIEW記法」と、
ReVIEW記法でマークアップした原稿を処理するツール類「ReVIEWツール」の総称です。

ReVIEWツールは、ReVIEW構文で記述されたファイル（ReVIEWファイル）を、TEXT/HTML/Markdown/EPUB/IDGXML@<fn>{about_idgxml}やLaTeXなどの形式で出力します。
また、組版ソフトウェア「pLaTeX」と組み合わせることで、@<kw>{PDF,Portable Document Format}への出力にも対応します。
#@# レビュー by わかめ htmlとepubが入るのにLaTeXとPDFがセットじゃない悲しみ！あとmarkdown。
#@# epubが外部ツールいらないのに対して、PDFは外部ツール(latex)いるので。markdownは出力できるの？後で確認しておく。

本章では、ReVIEWによってPDFの出力ができる環境を「ReVIEW環境」と定義し、各プラットフォームにおけるReVIEWとLaTeXのインストールに焦点を当てて解説します。

=== ReVIEWツール

#@# レビュー by わかめ ReVIEWツールてなに？処理系のこと？ "ReVIEW本体" とかのほうがよくね？
#@# ReVIEWツールなどの用語については「ReVIEW環境の構成」で定義済み。「ReVIEW」は、ReVIEW構文とReVIEWツール総括する用語としてるよ。このあたりは他の章とも話し合いながら統一したい。

ReVIEWツールは、単体のソフトウェアではありません。
特定の機能を持つ複数のプログラム（コマンド）セットで提供されています（@<table>{review_tools}）。

#@# レビュー by わかめ ↓ captionナイ。ReVIEWのコマンド一覧 とかでよさげ？
#@# レビュー by わかめ ----------- とかで区切るとテーブルのヘッダと本文が切れるので、2行目に入れたほうがよい。 https://github.com/kmuto/review/blob/master/doc/format.rdoc#%E8%A1%A8
//table[review_tools][主なコマンド一覧]{
コマンド	解説
-------------------------------------------------------
review-epubmaker	ReVIEWファイルから、EPUBを生成する
review-pdfmaker	ReVIEWファイルから、PDFを生成する
review-compile	ReVIEWファイルを、指定の形式に変換する
review-vol	ReVIEWファイルごとのサイズ、文字数、行数、@<br>{}ページ数を一覧で表示する
review-index	ReVIEWファイル全体の章、節、小節などの@<br>{}区切りごとのサイズ、文字数、行数を一覧で表示する
review-preproc	文字エンコードの変換やタブをスペースの置換処理などを行う
//}

//footnote[about_idgxml][Adobe InDesign CS2以降向けXML形式]

オリジナルのReVIEWツールは、プログラミング言語Rubyで実装されており、RubyのパッケージシステムRubyGemsで公開されています。

=== pLaTeX

LaTeXは、レスリー・ランポート（Leslie Lamport）氏によって開発された組版処理システムです（@<img>{logo_latex}）。

//image[logo_latex][LaTeXロゴ][scale=0.15]{
//}

ドナルド・クヌース（Donald E. Knuth）氏が開発した「TeX」に、マクロパッケージを追加する形で構築されています@<fn>{about_latex}。
pLaTeXは、LaTeXをさらに日本語に対応するように拡張したものです。

TeX(pLaTeX)は、TeXの構文でマークアップしたファイルをコンパイルして、DVI形式@<fn>{about_dvi}を出力します。
DVI形式は、PostScriptやPDFなどに変換できます。

//footnote[about_dvi][DeVice-Independent file format:文書の見た目を画像形式・表示デバイス・プリンタに依存しない形で記録したデータ形式]
//footnote[about_latex][@<href>{http://ja.wikipedia.org/wiki/LaTeX}]

ReVIEWツールとpLaTeXを組み合わせることで、ReVIEWファイルをPDFに出力することができます。

#@# レビュー by わかめ 他の章を読んでいる前提でないと、pLaTeXとPDFが結びつかないかも。
#@# 追記した。そもそもTeX自体はファイルをDVI形式に変換する役割しかないので、ちょっと説明がややこしい。

== Macでの環境構築

MacOSは、本稿執筆時点で、最もReVIEWの導入が容易なプラットフォームです。

なお、MacOS X 10.9(Mavericks)で検証しました。
利用しているMacOSのバージョンまたは環境によって、細部が異なる場合があるので注意してください。

//image[logo_macosx][MacOS X][scale=0.30]{
//}

=== ReVIEWツール

MacOSにReVIEWツールをインストールするには、二つの方法があります。

一つはRubyGemsを使ってインストールする方法。
もう一つが、GitHubで公開されているリポジトリからファイルをチェックアウトする方法です。

RubyGemsを使ってインストールすると、ReVIEWツールはRubyGemsの管理下にインストールされます。
パッケージの更新や、複数バージョンの切り替えには、RubyGemsを使いますが、MacOSに標準でインストールされているRubyGemsは、
gemのインストールに管理者権限が必要になります。

GitHubで公開されているリポジトリをcloneすると、常に最新のReVIEWツールを使用することができます。
インストール先はユーザーの管理下になり、RubyGemsのように管理者権限は必要ありません。パッケージの更新や複数バージョンの切り替えには、gitのコマンドを使います。

==== gemでインストール

MacOSには、RubyGemsが標準で含まれています。

RubyGemsを使ってReVIEWツールのパッケージ（gem）をインストールするには、以下のコマンドを実行します。

//cmd{
$ sudo gem install review
//}
#@# レビュー by わかめ わかめはrbenvユーザなので、sudoが必要ありません(むしろあるとひどい目にあう) もし、Permission関係で怒られたらsudoをつけて試してみてください。ぐらいの雑さがほしい。
#@# MacOS X 10.9で検証しているのでコマンドもそちらに準拠しています。rbenv使ってる人はsudoつけたらひどい目にあること解ってるだろうから、その人が自分用に読み替えればいいような気がするんだ。ちょっと様子見。

@<code>{sudo}による管理者パスワードの確認後、管理者権限でReVIEWツールがインストールされます。

==== GitHubからインストール
#@# レビュー by わかめ Github → GitHub
#@# Yes, GitHub

GitHubのReVIEWリポジトリ（@<href>{https://github.com/kmuto/review}）をcloneします。
なお、gitがインストールされていない場合は、Xcodeをインストールするなど準備をする必要があります。

//cmd{
$ git clone https://github.com/kmuto/review.git ~/

Cloning into 'review'...
(省略)
Checking connectivity... done
//}

cloneが完了したら、@<code>{review/bin}を、環境変数@<code>{PATH}に追加します。

//cmd{
$ echo 'export PATH=@<code>{~/review/bin}:$PATH' >> ~/.bash_profile
$ source ~/.bash_profile
//}
#@# レビュー by わかめ これgit cloneした場所依存なのでは。 git clone ... ~/ みたく、clone先を限定させたほうがいいかも
#@# Sounds good

また、cloneした最新版のReVIEWをgemとしてインストールする場合は、@<code>{rake install}を実行します（gem @<tt>{"bundler"}が必要です）。

//cmd{
$ cd review
$ sudo rake install
//}

以上で、ReVIEWツールのインストールは完了です。

=== MacTeX

MacOSにTeXをインストールする最も容易な方法は、MacTeXのパッケージを使うことです。

MacTeXの公式サイト（@<href>{http://tug.org/mactex/}）から、MacTeXをダウンロードします。
@<tt>{MacTeX-2013}のパッケージは2.3GBあります。標準でインストールすると4GBを超えるので、ディスクの空き容量には注意してください。

//indepimage[mactex_download][MacTeXのダウンロード][scale=0.15]

インストールを開始すると、利用許諾などの一般的な画面が表示されます。

//indepimage[mactex_install1][MacTeXのインストール][scale=0.35]

不要なパッケージをインストール@<tt>{installation Type}の画面で、
@<tt>{Customize}を選択します。

//indepimage[mactex_install4][「Customize」を選択する][scale=0.35]

ReVIEWに必要なパッケージは、@<tt>{TeXLive-2013}と@<tt>{GhostScript-9.07}です。
そのほかのパッケージはチェックを外してください。

//indepimage[mactex_install5][必要なパッケージのみチェックする][scale=0.35]

@<tt>{Install}を押して、MacTeXのインストールを完了します。

==== PDFの出力

ReVIEWの環境が構築できたら、サンプルをPDFに変換してみましょう。

ReVIEWツールをRubyGemsを使ってインストールした場合は、gemの中にサンプルが含まれているのでコピーして、@<code>{review-pdfmaker}を実行します。

//cmd{
$ cp -rf /Library/Ruby/Gems/2.0.0/gems/review-1.1.0/test/sample-book ~/
$ cd sample-book/src
$ review-pdfmaker config.yml
//}

上は、筆者の環境でReVIEWをインストールした場合です。RubyGemsやReVIEWのバージョン、システムの設定によってはディレクトリが異なる場合があります。
ReVIEWがインストールされているディレクトリを確認するには@<code>{gem which review}を実行します。

GitHubの場合は、リポジトリの中にサンプルが含まれているのでコピーして、@<code>{review-pdfmaker}を実行します。

//cmd{
$ cp -rf ~/review/test/sample-book ~/
$ cd sample-book/src
$ review-pdfmaker config.yml
//}

== Linuxでの環境構築

Linuxでの環境構築法を解説します。

なお、ここで紹介する環境の構築方法は、Ubuntu 12.04 LTS　64bit版（以下「Ubuntu」といいます）で検証しています。
利用しているディストリビューション、バージョンまたは環境によって、細部が異なる場合があるので注意してください。

//image[logo_linux][Linux][scale=0.50]{
//}

=== ReVIEWツール

UbuntuにReVIEWツールをインストールするには、二つの方法があります。

一つはRubyGemsを使ってインストールする方法。
もう一つが、GitHubで公開されているリポジトリからファイルをチェックアウトする方法です。

RubyGemsを使ってインストールすると、ReVIEWツールはRubyGemsの管理下にインストールされます。
パッケージの更新や、複数バージョンの切り替えには、RubyGemsを使いますが、gemのインストールに管理者権限が必要になります。

GitHubで公開されているリポジトリをcloneすると、常に最新のReVIEWツールを使用することができます。
インストール先はユーザーの管理下になり、RubyGemsのように管理者権限は必要ありません。パッケージの更新や複数バージョンの切り替えには、gitのコマンドを使います。

==== gemをインストール

まずはじめに、以下のコマンドを実行して、RubyGemsをインストールします。

//cmd{
$ sudo apt-get install rubygems

Reading package lists... Done
Building dependency tree       
Reading state information... Done

(省略)

The following NEW packages will be installed:
  binutils build-essential cpp cpp-4.6 dpkg-dev fakeroot g++ g++-4.6 gcc
  gcc-4.6 libalgorithm-diff-perl libalgorithm-diff-xs-perl
  libalgorithm-merge-perl libc-dev-bin libc6-dev libdpkg-perl libgomp1 libmpc2
  libmpfr4 libquadmath0 libreadline5 libruby1.8 libstdc++6-4.6-dev
  linux-libc-dev make manpages-dev ruby1.8 ruby1.8-dev rubygems
0 upgraded, 29 newly installed, 0 to remove and 0 not upgraded.
Need to get 33.6 MB of archives.
After this operation, 96.9 MB of additional disk space will be used.
Do you want to continue [Y/n]? y
//}

@<code>{sudo}の管理者パスワード確認の後、RubyGemsをインストールするにあたって必要なパッケージと、インストールの確認が表示されるので@<tt>{Y}を入力して実行します。

次に、以下のコマンドを実行して、ReVIEWツールのパッケージ（gem）をインストールします。

//cmd{
$ sudo gem install review
Fetching: review-1.1.0.gem (100%)
Successfully installed review-1.1.0
1 gem installed
Installing ri documentation for review-1.1.0...
Installing RDoc documentation for review-1.1.0...
//}

==== GitHubからインストール

GitHubのReVIEWリポジトリ（@<href>{https://github.com/kmuto/review}）をcloneします。
なお、gitがインストールされていない場合は、apt-getなどを使って準備をしておく必要があります。

//cmd{
$ git clone https://github.com/kmuto/review.git ~/

Cloning into 'review'...
(省略)
Checking connectivity... done
//}

cloneが完了したら、@<code>{review/bin}を、環境変数@<code>{PATH}に追加します。

//cmd{
$ echo 'export PATH=@<code>{~/review/bin}:$PATH' >> ~/.bash_profile
$ source ~/.bash_profile
//}

また、cloneした最新版のReVIEWをgemとしてインストールする場合は、@<code>{rake install}を実行します（gem @<tt>{"bundler"}が必要です）。

//cmd{
$ cd review
$ sudo rake install
//}

以上で、ReVIEWツールのインストールは完了です。

=== TeXLive

UbuntuでpLaTeXは、@<tt>{TeXLive CJK}パッケージとして提供されています。

しかし、@<tt>{TeXLive CJK}が、Ubuntuのパッケージとしてインストール可能になったのはUbuntuのバージョン12.10からで、
バージョン12.04にインストールする場合は、事前に12.10用のパッケージをバックポートしたリポジトリを登録する必要があります。

==== バックポートリポジトリを登録

以下のコマンドを入力して、Ubuntuのパッケージシステムにリポジトリを登録するユーティリティをインストールします。

//cmd{
$ sudo apt-get install python-software-properties

Reading package lists... Done
Building dependency tree       
Reading state information... Done
The following extra packages will be installed:
  python-pycurl
Suggested packages:
  libcurl4-gnutls-dev python-pycurl-dbg
The following NEW packages will be installed:
  python-pycurl python-software-properties
0 upgraded, 2 newly installed, 0 to remove and 0 not upgraded.
Need to get 73.0 kB of archives.
After this operation, 428 kB of additional disk space will be used.
Do you want to continue [Y/n]? y
//}

@<code>{sudo}の管理者パスワード確認の後、インストールの確認が表示されるので、@<tt>{Y}を入力して実行します。

次に、以下のコマンドを入力して、@<tt>{TeXLive CJK}のバックポートリポジトリを追加します。

//cmd{
$ sudo add-apt-repository ppa:texlive-backports

You are about to add the following PPA to your system:
 Backports of the latest TeX Live from Ubuntu 12.10 to Ubuntu 12.04 LTS
 More info: https://launchpad.net/~texlive-backports/+archive/ppa
Press [ENTER] to continue or ctrl-c to cancel adding it
//}

@<tt>{ENTER}キーを押すと、追加が完了します。

@<code>{apt-get update}で、先ほど追加したバックポートリポジトリを含めて、全てのパッケージを再読込します。

//cmd{
$ sudo apt-get update
//}

==== TeXLive CJKをインストール

以下のコマンドを実行して、@<tt>{TeXLive CJK}をインストールします。

//cmd{
$ sudo apt-get install texlive-lang-cjk texlive-fonts-recommended

Reading package lists... Done
Building dependency tree       
Reading state information... Done

(省略)

The following NEW packages will be installed:
  cmap-adobe-japan1 cpp cpp-4.6 doc-base fonts-ipaexfont-gothic
  fonts-ipaexfont-mincho fonts-ipafont-gothic fonts-ipafont-mincho ghostscript
  gs-cjk-resource gsfonts ko.tex-extra-hlfont latex-beamer latex-cjk-all
  latex-cjk-chinese latex-cjk-chinese-arphic-bkai00mp
  latex-cjk-chinese-arphic-bsmi00lp latex-cjk-chinese-arphic-gbsn00lp
  latex-cjk-chinese-arphic-gkai00mp latex-cjk-common latex-cjk-japanese
  latex-cjk-japanese-wadalab latex-cjk-korean latex-cjk-thai
  latex-fonts-thai-tlwg latex-xcolor libcupsimage2 libfile-basedir-perl
  libfile-desktopentry-perl libfile-mimeinfo-perl libfontenc1 libgl1-mesa-dri
  libgl1-mesa-glx libglapi-mesa libgraphite3 libgs9 libgs9-common libijs-0.35
  libjbig2dec0 libkpathsea6 liblcms2-2 libllvm3.0 libmpc2 libmpfr4
  libpaper-utils libpaper1 libpoppler19 libptexenc1 libreadline5 libruby1.8
  libutempter0 libuuid-perl libx11-xcb1 libxaw7 libxcb-glx0 libxcb-shape0
  libxfont1 libxmu6 libxtst6 libxv1 libxxf86dga1 libxxf86vm1 libyaml-tiny-perl
  lmodern luatex pgf preview-latex-style prosper ps2eps ruby ruby1.8 swath
  tcl8.4 tex-common texlive-base texlive-binaries texlive-common
  texlive-doc-base texlive-doc-zh texlive-extra-utils texlive-font-utils
  texlive-generic-recommended texlive-lang-cjk texlive-latex-base
  texlive-latex-base-doc texlive-latex-extra texlive-latex-extra-doc
  texlive-latex-recommended texlive-latex-recommended-doc texlive-luatex
  texlive-pictures texlive-pictures-doc texlive-pstricks texlive-pstricks-doc
  thailatex tk8.4 x11-utils x11-xserver-utils xbitmaps xdg-utils
  xfonts-encodings xfonts-utils xterm tex-gyre texlive-fonts-recommended
  texlive-fonts-recommended-doc tipa ttf-marvosym
0 upgraded, 108 newly installed, 0 to remove and 2 not upgraded.
Need to get 783 MB of archives.
After this operation, 1,433 MB of additional disk space will be used.
Do you want to continue [Y/n]? y
//}

インストールの確認が表示されるので、@<tt>{Y}を入力して実行します。

TeXLiveは非常に大きなパッケージなので、インストールには時間がかかります。

以上で、TeXLiveのインストールは完了です。

==== PDFの出力

ReVIEWの環境が構築できたら、サンプルをPDFに変換してみましょう。

ReVIEWツールをRubyGemsを使ってインストールした場合は、gemの中にサンプルが含まれているのでコピーして、@<code>{review-pdfmaker}を実行します。

//cmd{
$ cp -rf /var/lib/gems/1.8/gems/review-1.1.0/test/sample-book ~/
$ cd sample-book/src
$ review-pdfmaker config.yml
//}

上は、筆者の環境でReVIEWをインストールした場合です。RubyGemsやReVIEWのバージョン、システムの設定によってはディレクトリが異なる場合があります。
ReVIEWがインストールされているディレクトリを確認するには@<code>{gem which review}を実行します。

GitHubの場合は、リポジトリの中にサンプルが含まれているのでコピーして、@<code>{review-pdfmaker}を実行します。

//cmd{
$ cp -rf ~/review/test/sample-book ~/
$ cd sample-book/src
$ review-pdfmaker config.yml
//}

== Windowsでの環境構築

残念なことに、WindowsにReVIEWをインストールするのは容易ではありません。

@<chapref>{introduction}でも述べたとおり、Windows上でReVIEWを動作させるにはCygwinなどの環境を整備する必要があるのです。

//image[logo_windows][Windows 8.1][scale=0.35]{
//}

開発者の武藤氏によって、VirtualBox用の仮想イメージ（Debian）が公開されているので、そちらを使うのが最も簡単な方法です。

KeN's GNU/Linux Diary @<href>{http://d.kmuto.jp/20130811.html}
