= スタイル解説

//lead{
ReVIEWで生成する原稿の見た目を、美しくブラッシュアップしたくはありませんか？

本章では、ReVIEWで生成される各種ファイルの見た目を変更する方法と、実際にカスタマイズする方法を紹介します。
//}

#@# TODO レビュー by わかめ スタイル が何を指すかちょっと特定できない。ReVIEWスタイル→コーディング規約？ 各ファイルのスタイル→HTMLに対するCSS的な？
#@# TODO レビュー by lead に "ReVIEWで書いた原稿の見た目を、美しくブラッシュアップしたくはありませんか？" ていう行を最初に入れるべきかと。それでスタイルの意味合いが一意になる。

== スタイルファイルの種類

@<chap>{introduction}で紹介した通り、ReVIEWは、書籍の出版に適したテキストベースの軽量マークアップ言語「ReVIEW記法」と、
ReVIEW記法でマークアップした原稿を処理するツール類「ReVIEWツール」の総称です。

ReVIEWは、ReVIEW記法でマークアップされたファイル（以下、「ReVIEWファイル」といいます）を、TEXT/HTML/EPUB/Markdown/IDGXML@<fn>{about_idgxml}およびLaTeX（PDF）の形式で出力します。
#@# レビュー by わかめ 一応markdownへの変換もサポートされている。PDFを取り上げるならepubも取り上げたほうがよさげ。inaoとかewbは使わないからいいかー。感ある。

//footnote[about_idgxml][Adobe InDesign CS2以降向けXML形式]

本章では、ReVIEWが出力する各種ファイルの形式をはじめ、表示内容に影響する入力項目をまとめて「スタイル」と呼びます。
#@# レビュー by わかめ 規定の入力項目って何？？？コマンドラインオプション？？？
#@# .ymlで定義していて入力が必須のもの。表現を変更。
また、スタイルを設定するファイルをまとめて「スタイルファイル」と呼びます。

ReVIEWのスタイルファイルには、以下のものがあります。

=== .yml

ReVIEWで最も重要なスタイルファイルが.ymlファイルです。

.ymlファイルは、YAML@<fn>{about_yml}形式で記述し、書籍のタイトルや表画像、ページの大きさや目次に含める見出しの深さなど、
ReVIEWファイルを変換する際に必要となる設定を記述します。

#@# レビュー by わかめ ファイル名に規定ってないんだっけ？config.yml？ .ymlは、〜〜〜 は .jsonは、ReVIEWの代表的なスタイルファイルです。って書かれている感じの違和感がある。ふぇ？ymlってデータファイルじゃね？みたいな。
//footnote[about_yml][YAML Ain't a Markup Language: 構造化データやオブジェクトを文字列にシリアライズ（直列化）するためのデータ形式の一種。]
#@# レビュー by わかめ Ruby界隈で多く使われている。とか一文あってもいいかも。

#@# レビュー by あめ玉 わかめの1つ目のレビューに同意。あと、これを「スタイルファイル」と呼ぶのにも違和感があった。これはプロジェクト全体のメタデータであって、見栄え（スタイル）を収録するものではないと思う。
#@# ここではYAMLという単語を知らない読者に「YAMLはデータ形式の一種」であることが解ってもらえれば十分です。footnoteの存在は読者の集中を阻害すると考えているので、最低限の記述にとどめる方針です。
#@# YAMLをスタイルファイルに含めても良いのかについては議論の余地があると思います。その上で、twosideやページサイズの決定、ページ起こしの変更など、かなりの部分をこのファイルで処理しているので、今回はこの章に収録することとしました。

@<list>{config_yaml}は、本書で使っている.ymlファイルです。

#@# レビュー by わかめ ↓ 日光企画？Android Standard？
#@# done
//list[config_yaml][config.yml]{
# review-epubmaker向けの設定ファイルの例。
# yamlファイルをReVIEWファイルのある場所に置き、
# 「review-epubmaker yamlファイル」を実行すると、<bookname>.epubファイルが
# 生成されます。
# このファイルはUTF-8エンコーディングで記述してください。

# ブック名(ファイル名になるもの。ASCII範囲の文字を使用)
bookname: book
# 書名
booktitle: はじめてのReVIEW
# 著者
aut: TechBooster
prt: 日光企画
prt_url:  http://techbooster.org/
edt: mhidaka
dsr: yuya
date: 2013-12-10
rights: |
  (C) 2013 techbooster.org
description: ReVIEW執筆経験者による執筆ノウハウをまとめました。
# 以下はオプション
#prt: 出版社
# asn: Associated name
# ant: Bibliographic antecedent
# clb: 貢献者
# ill: イラストレータ
# pht: 撮影者
# trl: 翻訳者
# rights: 権利表記
# description: ブックの説明
#
# coverfile: カバーページのbody要素内に挿入する内容を記述したファイル名
coverfile: _cover.html
# coverimage: 表紙用画像ファイル
coverimage: cover.jpg
# 固有IDに使用するドメイン
urnid: http://techbooster.org/book/Beginners-ReVIEW
# CSSファイル (yamlファイルおよびReVIEWファイルを置いたディレクトリにあること
stylesheet: main.css
# LaTeX用のdocumentclassを指定する
texdocumentclass: ["jsbook", "b5j,twoside,openany"]
texstyle: techbooster-doujin
# 目次として抽出するレベル
toclevel: 2
# セクション番号を表示するレベル
secnolevel: 2
# review-compileに渡すパラメータ
params: --stylesheet=main.css
# 目次生成用？
mytoc: true
# 奥付生成用
colophon: true
pubhistory: |
  2013年12月31日  初版発行 v1.0.0
debug: true
//}

.ymlファイルは、ReVIEWのコンパイル時に@<code>{--yaml}オプションで指定します。
#@# レビュー by わかめ "も"？ デフォルトはconfig.ymlなんだっけ？デフォルトはconfig.ymlですっていう言及がなさげ。
#@# done

//cmd{
review-compile --target=html --yaml=config.yml style_customize.re
//}

=== .sty

.styは、LaTeX（PDF）を出力する際に必要な「組版に関する設定」を記述するファイルで、LaTeXのスタイル形式で記述します。
#@# レビュー by わかめ LaTeX が正しいはず。全体的にアレしてちょー
#@# done

@<list>{config_style}は、本誌で採用している.styファイルです。

//list[config_style][sty/techbooster.sty]{
%% サンプルコードを更に小さく
\renewenvironment{reviewemlist}{%
  \medskip\footnotesize\begin{shaded}\setlength{\baselineskip}{1.2zw}\begin{alltt}}{%
  \end{alltt}\end{shaded}}

\renewenvironment{reviewlist}{%
  \begin{shaded}\footnotesize\setlength{\baselineskip}{1.2zw}\begin{alltt}}{%
  \end{alltt}\end{shaded}\par\vspace*{0.5zw}}

\renewenvironment{reviewcmd}{%
  \color{white}\medskip\footnotesize\begin{shadedb}\setlength{%
    \baselineskip}{1.2zw}\begin{alltt}}{%
  \end{alltt}\end{shadedb}}

%% from review-pdfmaker
\usepackage{fancyhdr}
\usepackage{ulem}
\pagestyle{fancy}

\fancyhead{}
\fancyhead[LE]{\gtfamily\sffamily\bfseries\upshape \leftmark}
\fancyhead[RO]{\gtfamily\sffamily\bfseries\upshape \rightmark}
\cfoot{\thepage}

\renewcommand{\sectionmark}[1]{\markright{\thesection~#1}{}}
\renewcommand{\chaptermark}[1]{%
  \markboth{\prechaptername\ \thechapter\ \postchaptername~#1}{}}
\renewcommand{\headfont}{\gtfamily\sffamily\bfseries}

\fancypagestyle{plainhead}{%
\fancyhead{}
\fancyfoot{} % clear all header and footer fields
\fancyfoot[CE,CO]{\thepage}
\renewcommand{\headrulewidth}{0pt}
\renewcommand{\footrulewidth}{0pt}}

\hypersetup{colorlinks=false}
%%Helveticaを使う
\renewcommand{\sfdefault}{phv}

\sloppy

\cfoot{\thepage}

\def\cleardoublepage{%
\clearpage%
\if@twoside%
   \ifodd \c@page \else \hbox{}\thispagestyle{plainhead}\newpage%
           \if@twocolumn\hbox{}\thispagestyle{plainhead}\newpage\fi%
   \fi%
\fi%
}
//}

スタイルの指定は、.ymlの@<code>{texstyle}の項目に、適用するスタイルファイルの名前を指定して行います。

#@# レビュー by わかめ どうやるの？？ymlを複数用意してymlを切り替えるのかな？
#@# done

==== PDF出力におけるReVIEWの役割

PDFを出力するプロセスにおいてReVIEWは、ReVIEWファイルをLaTeXのソースファイルに変換する以上のことはしていません。

実際に、@<code>{review-compile}コマンドの出力の形式を指定するオプション@<code>{--target}に"PDF"の値を指定できません。

しかし、@<code>{review-pdfmaker}コマンドを使った場合、ReVIEWファイルをPDFとして出力しています。
@<code>{review-pdfmaker}コマンドは、どのような処理をしているのでしょうか。

@<code>{review-pdfmaker}コマンドは、@<code>{review-compile}コマンドの出力形式に@<code>{latex}と指定することで、いったんLaTeXのソースファイルを出力しています。

ここで得られたLaTeXのソースファイルをLaTeXのツールで処理してDVIファイルに変換。
最後に、DVIファイルをPDF形式に変換するという一連のプロセスを自動化したものが、@<code>{review-pdfmaker}コマンドなのです。

//image[how_to_convert_re_to_pdf][ReVIEW形式のファイルをPDFに変換][scale=0.35]{
//}

=== .css

.cssは、HTMLを出力する際に適用するスタイルを記述するファイルで、@<kw>{CSS,Cascading Style Sheet}形式で記述します。

また、@<code>{review-epubmaker}コマンドで出力するEPUB形式のスタイルにも適用されます。

#@# レビュー by わかめ なんの略語かを示すだけなら @<kw>{CSS,Cascading Style Sheet}がおぬぬめ！
#@# done

#@# レビュー by わかめ このCSSは本書で使っているものじゃないの？
#@# スタイルシートはPDFの結果に影響しないから、あくまでサンプルという扱いにしてます
//list[config_css][CSSのサンプル]{
@charset "utf-8";
/* Table
*/
table {
    margin: 0 auto 2em auto;
    border-collapse: collapse;
    padding: 0;
}
table tr th {
    background-color: #eee;
    border:1px #aaa solid;
    font-size: 0.75em;
    font-weight: normal;
}
table tr td {
    padding: 0.3em;
    border:1px #aaa solid;
    font-size: 0.75em;
}

p.tablecaption, table caption, div.table p.caption {
    margin: 0;
    text-align: center;
    color: #666;
    font-size: 0.75em;
    font-weight: bold;
    text-indent: 0;
}
/* Quote */
blockquote {
    margin: 2em 0 2em 0;
    padding: 0.3em 1em;
    border: 1px #aaa solid;
}
blockquote p {
    text-indent: 0em;
}

/* Code Block */
div.code, div.caption-code, div.source-code, div.emlist-code, div.emlistnum-code {
    margin: 1em 0 2em 2em;
    padding: 0;
}
div.emlist-code p.caption {
    border-left: 7px solid #06CD23;
}
pre.emlist, pre.source, pre.list {
    margin: 0;
    padding: 5px;
    border: 1px #aaa solid;
    background-color: #eee;
}
div p.caption {
    margin: 0;
    color: #666;
    font-size: 0.75em;
    font-weight: bold;
}
//}

生成するHTMLやEPUBに適用するCSSは、@<code>{review-compile}コマンドの@<code>{--stylesheet}オプションにファイル名を指定します。

また、ファイルが複数ある場合は、コンマ区切りで区切って列挙します。

//cmd{
review-compile --target=html --stylesheet=main.css style_customize.re
//}

または、.ymlファイルの@<code>{stylesheet:}の項目に適用したい.cssファイルを指定することもできます。
こちらもファイルが複数ある場合は、コンマ区切りで区切って列挙します。

stylesheetを指定した.ymlファイルは、ReVIEWのコンパイル時に@<code>{--yaml}オプションで指定します。

//cmd{
review-compile --target=html --yaml=config.yml style_customize.re
//}

#@# レビュー by わかめ 指定したCSSファイルがリンクされるのかincludeされるのかちょっと気になる。
#@# done

指定した.cssは、HTMLの場合、外部のスタイルシートとして参照されます。
EPUBの場合は出力されるファイルの内部に取り込まれ、そのままEPUBの見た目として適用されます。

#@# レビュー by わかめ ここまでのまとめがほしいなー。 yml→全部 css→epub sty→PDF みたいな。
#@# done

=== スタイルファイルまとめ
#@# レビュー by わかめ スタイルのカスタマイズサンプル とか スタイルのカスタマイズ例 みたいな節タイトルにしたほうがいいと思う

ここまで、ReVIEWの３つのスタイルファイル（.yml/.sty/.css）を紹介しました。

: .yml
    ReVIEWファイルを変換する際に必要となる設定を記述します。
    内容は、ReVIEWが出力する全てのファイルに影響します。

: .sty
    ReVIEWでLaTeX（PDF）を出力する際の「組版に関する設定」を記述します。

: .css
    ReVIEWでHTMLやEPUB形式で出力する際の見た目を記述します。

#@# レビュー by わかめ うーん箇条書きを用いるべきでは… * と ** 使って。
#@# done

次に、これら３つのファイルを編集して、ReVIEWが出力するファイルの見た目を、実際にカスタマイズする方法を見ていきましょう。

== ページサイズを変更する

PDF形式で出力するページサイズを指定するには、.ymlファイルの@<code>{textdocumentclass:}項目の２番目の値を設定します（@<list>{change_pagesize}）。

この設定は、LaTeXにおけるドキュメントクラスのオプションに該当します。複数のオプションがある場合は、カンマで区切って列挙します。

//list[change_pagesize][ページサイズをa4jに指定している]{
texdocumentclass: ["jsbook", "a4j"]
//}

//table[papersize][設定できるページサイズ]{
値	用紙サイズ
-----------
a4paper	A4
b5paper	B5
a4j	A4
b5j	B5
//}

@<table>{papersize}は、@<code>{jsbook}ドキュメントクラスに設定できる代表的な用紙サイズです。
指定するドキュメントクラスによっては、設定できる値が異なる場合があるので注意してください。

A4やB5を指す値が重複しているのは、ページサイズに余白の設定を含んでいるためです。

たとえば、@<code>{a4paper}は@<code>{a4j}に比べ、@<code>{b5paper}は@<code>{b5j}に比べ余白が大きく、本文領域が狭くなっています。

== 目次に表示する項目をカスタマイズする

目次として抽出する章や節の深さを変更するには、.ymlファイルの@<code>{toclevel:}項目を設定します（@<list>{toclevel}）。

//list[toclevel][抽出レベルを設定]{
toclevel: 2
//}

抽出レベルを変更すると、値に応じた深さの見出しを出力します（@<img>{toclevel2}および@<img>{toclevel3}）。

//image[toclevel2][toclevel:2を指定した場合の目次][scale=0.35]{
//}

//image[toclevel3][toclevel:3を指定した場合の目次][scale=0.35]{
//}

== 余白を調節する

PDFで出力するページの余白を指定するには、.styファイルに@<code>{\geometry}を設定します（@<list>{set_margin}）。

//list[set_margin][余白を設定]{
\geometry{top=18mm,bottom=23mm,left=24mm,right=24mm}
//}

指定できる単位は、@<code>{cm}, @<code>{mm}の他にもLaTeXでサポートされている@<code>{in}, @<code>{pt}, @<code>{em/ex}, @<code>{zw/zh}, @<code>{Q}などがあります。

== 章のページ起こしを指定する

PDFで出力する章（@<code>{chapter}）ごとのページ起こしを指定できます。
#@# レビュー by わかめ ページ起こしって何？？

文書内で新しい章が始まるときに、見開きの左右どちらのページから始めるかを「ページ起こし」といいます。

PDF形式で出力するページ起こしを指定するには、.ymlファイルの@<code>{textdocumentclass:}項目の２番目の値を設定します（@<list>{change_pagesize}）。

この設定は、LaTeXにおけるドキュメントクラスのオプションに該当します。複数のオプションがある場合は、カンマで区切って列挙します。

//list[start_page][見開き、章は左右どちらのページでも開始するように設定している]{
texdocumentclass: ["jsbook", "a4j,twoside,openany"]
//}

//table[start_page][jsbookで設定できるオプション]{
値	設定
openright	必ず右側ページから開始する（デフォルト）
openany	章は前章の次のページから開始する
//}

@<list>{start_page}では、まず、@<code>{twoside}オプションを指定することで、「見開きの文書」であることを設定しています。

次に、@<code>{openany}オプションを指定して、章は左右どちらのページでも開始するように設定しています。

jsbookドキュメントクラスは、このオプションを指定しない場合、標準で@<code>{oneside}を適用します。
その場合、@<code>{openright}などの指定が無効になる他、左右のページ位置に応じたスタイルの設定は無視されるので、注意が必要です。

オプションとして指定できる値は、使用するドキュメントクラスに応じて設定できる値が異なるので注意してください。

たとえば、ドキュメントクラス@<code>{jsbook}には、@<code>{openleft}のオプションはありませんが、@<code>{openleft}を指定できるドキュメントクラスも存在します。

===[column] 「ページ起こし」とは
#@# レビュー by わかめ これはもうちょっと前に置いたほうが…
#@# done
前述の通り、「ページ起こし」とは、文書内で新しい章が始まるときに、見開きの左右どちらのページから始めるかを定めるものです。

章の区切りで、必ず番号の大きいページから始まる場合を「片起こし」と呼びます。
@<code>{openright}を指定した場合が片起こしとなり、章は必ず、見開きの番号の大きい方のページから始まります（@<img>{openright}）。

//image[openright][章は必ず見開きの右側のページから始まる][scale=0.35]{
//}

一方、片起こしの反対が「両起こし」と呼ばれます。両起こしは必ず、見開きの番号の小さい方のページから始まります。

両起こしに該当する指定はありません。@<code>{openany}を指定した場合、新しい章は、
前の章が終わった次のページから始まります。この場合は、両起こしになる場合があります（@<img>{openany}）。

//image[openany][oepnanyの場合、章はどちらのページからも始まる][scale=0.35]{
//}

また、章が左右どちらから始まっているかで、それぞれ「左起こし」「右起こし」と呼ぶこともあります。

===[/column]

== ヘッダとフッタをカスタマイズする

PDF形式で出力するヘッダとフッタの表示をカスタマイズできます。

表示する位置や内容は、.styファイルの@<code>{\fancyhead}と@<code>{\fancyfoot}で設定します。

//list[header_footer][ヘッダとフッタの設定]{
\fancyhead{}
\fancyhead[LE]{\gtfamily\sffamily\bfseries\upshape \leftmark}
\fancyhead[RO]{\gtfamily\sffamily\bfseries\upshape \rightmark}
\cfoot{\thepage}
//}

@<list>{header_footer}では、最初に@<code>{\fancyhead}を初期化した後、実際に表示するヘッダの内容を設定しています。

具体的には、ページ番号が偶数かつ見開きの左側ページの場合、ヘッダの左側に@<code>{\leftmark}を表示（@<img>{header_left}）。
ページ番号が奇数かつ見開きの右側ページの場合、ヘッダの左側に@<code>{\rightmark}を表示するように設定しています（@<img>{header_right}）。

//image[header_left][左ページに表示するヘッダ][scale=0.35]{
//}

//image[header_right][右ページに表示するヘッダ][scale=0.35]{
//}

なお、@<code>{\leftmark}と@<code>{\rightmark}は、LaTeXのコマンドとして標準で定義されています。

一般的には@<code>{\leftmark}が「章の名前（ReVIEWでは@<code>{=}に続く名前）」、
@<code>{\rightmark}が「節名（ReVIEWでは@<code>{==}に続く名前）」にそれぞれ該当します。

このことから解るとおり、これらのコマンドは、ページ番号の偶数奇数や見開きのページ位置（左右）の組み合わせを、
シンボルを指定することで個別に設定できます@<fn>{indivisual_symbols}。

//footnote[indivisual_symbols][ページ番号の奇数・偶数と、見開きのページ位置がそれぞれ独立しているのは、書籍によっては綴じ方向が異なる場合があるためです。]

たとえば、@<code>{\fancyhead[LE]}は、「偶数ページかつ見開き左側ページのヘッダ」という意味になります。

それぞれのシンボルの意味については@<table>{symbol}を参照してください。

//table[symbol][シンボルと意味]{
シンボル	意味
------------
E	偶数ページ
O	奇数ページ
L	左側
C	中央
R	右側
H	ヘッダ
F	フッタ
//}

また、ページスタイルに応じて個別に設定を適用することもできます。
@<list>{header_footer_context}は、ページスタイルが@<code>{plainhead}の場合のヘッダとフッタの内容を設定しています。

//list[header_footer_context][ヘッダとフッタの設定]{
\fancypagestyle{plainhead}{
  \fancyhead{}
  \fancyfoot{}
  \fancyfoot[CE,CO]{\thepage}
  \renewcommand{\headrulewidth}{0pt}
  \renewcommand{\footrulewidth}{0pt}
}
//}

== 既存のスタイルを変更する

PDFで出力する本文やリスト、図表に適用するスタイルを個別にカスタマイズすることができます。

前述の通りReVIEWは、ReVIEW形式のファイルをPDFへ変換する前に、LaTeXのソースファイルを出力します。

例えば、ReVIEWファイル@<list>{change_pagesize2}は、LaTeXソースファイルでは、@<list>{reviewlist_latex}になります。

//list[change_pagesize2][ReVIEW記法]{
 \\list[change_pagesize][ページサイズをa4jに指定している]{
 texdocumentclass: ["jsbook", "a4j"]
 \\}
//}

//list[reviewlist_latex][LaTeXソースファイル]{
\reviewlistcaption{リスト3.4: ページサイズをa4jに指定している}
\begin{reviewlist}
texdocumentclass: ["jsbook", "a4j"]
\end{reviewlist}
//}

@<code>{\begin{reviewlist}}と@<code>{\end{reviewlist}}で囲まれた範囲をEnvironment（環境）と言い、
環境の中にあらかじめ設定したスタイルを適用できます。

そして、.styファイルで環境を再定義することで、これらのスタイルを変更できます。

@<list>{renewenvironment}は、@<code>{renewenvironment}によって環境@<code>{reviewlist}を再定義し、
環境中の文字の大きさを小さめ（@<code>{\footnotesize}）に設定しています。

//list[renewenvironment][環境の再定義]{
\renewenvironment{reviewlist}{%
  \begin{shaded}\footnotesize\setlength{\baselineskip}{1.2zw}\begin{alltt}}{%
  \end{alltt}\end{shaded}\par\vspace*{0.5zw}}
//}

また、環境だけでなく、コマンドを再定義することもできます。

@<list>{renewcommand}は、@<code>{renewcommand}によってコマンド@<code>{reviewlistcaption}を再定義し、
文字の大きさを小さめ（@<code>{\footnotesize}）に設定しています。

//list[renewcommand][コマンドのオーバーライド]{
\renewcommand{\reviewlistcaption}[1]{
  \medskip\noindent{\footnotesize #1}\vspace*{-1.3zw}
}
//}

再定義したい環境名やコマンドを探すには、LaTeXのソースファイルを見るのが良いでしょう。

変換後のLaTeXのソースファイルを確認するには、@<code>{review-compile}するか、
@<code>{review-pdfmaker}を実行するときに指定する.ymlファイルでデバッグ機能を有効に設定します（@<list>{debug_true}）。

//list[debug_true][デバッグの有効化]{
debug: true
//}

@<code>{\renewenvironment}や@<code>{\renewcommand}は、既存の定義を丸ごと変更してしまいます。

したがって、現在適用しているスタイルの一部だけ変更したい場合は、その環境やコマンドの現在の定義を確認してから、一部を変更する作業が必要になります。

環境やコマンドの定義を調べるには、
ReVIEW関係であれば@<href>{https://github.com/kmuto/review}の@<code>{review/lib/review/review.tex.erb}にまとめられています@<fn>{review_tex_erb}。

ここに記載のない環境やコマンドは、LaTeX及び各パッケージで定義されている可能性があります。
まずは、どのパッケージで定義されているかを確認するところから始める必要があります。

== 本の構成を変更する

印刷所へ入稿する原稿を制作していると、ReVIEWが標準で用意している構成そのものを変更する必要に迫られる時があります。

その場合、.ymlや.cssを配置しているディレクトリの下に@<code>{layouts/layout.tex.erb}を置くと、ReVIEWが出力するLaTeXソースファイルの構成を変更できます。

ReVIEWは、通常は@<href>{https://github.com/kmuto/review}の@<code>{review/lib/review/review.tex.erb}を、
LaTeXのソースファイルのテンプレートとして読み込みますが、@<code>{layouts/layout.tex.erb}がある場合、そちらを優先して適用します。

//footnote[review_tex_erb][2013年11月時点。最新の情報についてはGitHubのReVIEWリポジトリを参照してください。]

カスタマイズに当たっては、@<code>{review/lib/review/review.tex.erb}を@<code>{layouts/layout.tex.erb}にコピーして変更すると良いでしょう。

//image[how_to_convert_re_to_pdf2][layout.tex.erbの取り扱い][scale=0.35]{
//}

=== 構成の変更事例 - 通しノンブル

たとえば筆者の場合、入稿当日に印刷所より、全てのページに「通しノンブルが必要」との指摘を受け、慌てて構成を変えると言うことがありました。

「通しノンブル」とは、印刷する全てのページに1から始まるノンブル（ページ番号）を出力することを言います。
印刷、製本の過程でページの抜けや入れ替わりがないことを確認するために必要となり、後々のトラブルを防止するために入稿規程に含めている印刷所も少なくありません@<fn>{hidden_number}。

//footnote[hidden_number][製本後に読者の目に触れない場所（綴じ目の奥など）にノンブルを表示する「隠しノンブル」を認めている印刷所もあります]

ReVIEWの標準構成は、前書き(preface)や目次についてはローマ数字(i, ii, iii...)でのノンブル。
本文についてはアラビア数字(1, 2, 3...)でノンブルを出力します。また、前書きと本文でノンブルがリセットされるので、本文は必ず1から始まってしまいます。

さらに、扉や奥付にはノンブルそのものが表示されません。
扉や奥付を含む全てのページに、通しノンブルが表示されている必要があるとの指摘でした。

この問題に対応するためには、ReVIEWが出力する構成そのものを変更する必要があります。

@<list>{number}が、実際に@<code>{layout.tex.erb}を変更した内容です。

@<code>{\frontmatter}の位置をタイトルページの前に移動し、ノンブル表記を@<code>{arabic}に指定しています。

次に、@<code>{\thispagestyle}でページスタイルをノンブルを表示しない（@<code>{empty}）から@<code>{plainhead}に変更。同様の変更は奥付にも適用します。

ここで指定しているページスタイル@<code>{plainhead}は、.sty側で定義しています（@<list>{header_footer_plainhead}）。

ヘッダとフッタを全て消去して、フッタの中央にノンブルのみ表示。ヘッダとフッタの横線も@<code>{0pt}として非表示にしています。

@<code>{\setcounter{page}}でページ番号を1と設定しているのは、このままでは表紙もページ数に含まれ、扉が2ページ目と表記されてしまうためです。
表紙をページ数に含めないため、今回このように指定しました。

前書きや目次から本文に切り替わるタイミングでページ数を引き継いでいるのが@<code>{\mainmatter}の次の行にある@<code>{\continuenumber}です。

@<code>{\continuenumber}は、@<code>{\begingroup}内で定義しているマクロで、直前のページ数を引き継いで@<code>{\setcounter{page}}で設定しています。

こうすることで、本来はリセットされるページカウンタを再設定しています。

//list[number][通しノンブルにする変更]{
diff --git a/article/layouts/layout.tex.erb b/article/layouts/layout.tex.erb
index 4a83d4c..b9e72bd 100644
--- a/article/layouts/layout.tex.erb
+++ b/article/layouts/layout.tex.erb
@@ -176,6 +176,9 @@
 
 \reviewmainfont
 
+\frontmatter
+\pagenumbering{arabic}
+
 <% if values["titlepage"] %>
 <% if custom_titlepage %>
 <%= custom_titlepage %>
@@ -188,7 +191,8 @@
   \end{center}
   \clearpage
   <% end %>
-\thispagestyle{empty}
+\thispagestyle{plainhead}
+\setcounter{page}{1}
 \begin{center}%
   \mbox{} \vskip5zw
    \reviewtitlefont%
@@ -207,9 +211,6 @@
 <% end %>
 <% end %>
 
-\renewcommand{\chaptermark}[1]{{}}
-\frontmatter
-
 %% preface
 <%= values["pre_str"] %>
 
@@ -218,8 +219,18 @@
 \tableofcontents
 <% end %>
 
-\renewcommand{\chaptermark}[1]{\markboth{\prechaptername\thechapter\postchapter
+\begingroup
+  \cleardoublepage
+  \edef\continuenumber{\endgroup
+    \noexpand\mainmatter
+    \setcounter{page}{\the\value{page}}%
+  }
+
 \mainmatter
+\continuenumber
+
+\renewcommand{\chaptermark}[1]{\markboth{\prechaptername\thechapter\postchapter
+
 <%= values["chap_str"] %>
 \renewcommand{\chaptermark}[1]{\markboth{\appendixname\thechapter~#1}{}}
 \reviewappendix
@@ -228,7 +239,7 @@
 <% if values["colophon"] %>
 %% okuduke
 \reviewcolophon
-\thispagestyle{empty}
+\thispagestyle{plainhead}
 
 \vspace*{\fill}
 
//}

//list[header_footer_plainhead][plainheadページスタイル]{
\fancypagestyle{plainhead}{
  \fancyhead{}
  \fancyfoot{}
  \fancyfoot[CE,CO]{\thepage}
  \renewcommand{\headrulewidth}{0pt}
  \renewcommand{\footrulewidth}{0pt}
}
//}

== まとめ

本章では、ReVIEWが生成する各ファイルの基本的な設定や、見た目（スタイル）に関わる変更について解説しました。

スタイルの変更の事例で、LaTeXに関わる記述が多かったのは、筆者が主にPDF出力を目的としてReVIEWを利用していることもありますが、
カスタマイズの自由度が最も高く、また、カスタマイズが困難であるのも、LaTeXであるからです。

LaTeXのカスタマイズについては、奥村晴彦氏の「LATEX2e 美文書作成入門」@<fn>{book_latex2e}が参考になりました。

//footnote[book_latex2e][「LATEX2e美文書作成入門」 @<href>{http://www.amazon.co.jp/dp/4774160458} - 奥村晴彦著 技術評論社刊]
#@# レビュー by わかめ Amazonへのhref貼ったら？@<href>{LATEX2e 美文書作成入門,http://www.amazon.co.jp/dp/4774160458}
#@# done

各出力形式におけるReVIEWの役割を理解した上で、それぞれのスタイルファイルを正しくカスタマイズすることを心がけてください。
