= 執筆を始める

#@# by amedama レビュー者向け注記: 本文をレビューしていただき誠にありがとうございます
#@# 現時点ではまずスク<del>水</del>ショがおかしいです。また特に後半、文面が不足してたりぼっこわれてたりしますので、その点は好き勝手にボコっていいです。より重要なのは、この構成で本著の入門者向け記事に適切にポインタを張れているか、実際にこれを読んでいって使い方のさわりに触れられているかです。テーブル記法に到達できてない、といった問題はともかく、ここで通常の執筆フローにものすごく不足しているものがあるとまずいので、それがあったら指摘してください。
#@# レビュー by わかめ <del></del>は@<del>{}に置き換えるべき もっと真面目にReVIEW脳してください！
#@# レス by あめ玉: ここ記法書いてに書いて副作用があったらどうするのさ！（そっちか

//lead{
本章ではReVIEWを用いて原稿を書いていく過程を紹介します。@<fn>{unix_used}
//}

#@# あめ玉コメント: ここで唐突にfootnoteに違和感を覚える可能性もなきにしもあらず。これは後半で実際にfootnoteを使う例を示すためもあってやってます。

//footnote[unix_used][読者がUNIX系OS上でコマンドやエディタの操作がある程度出来ることを想定しています。]

== プロジェクトを作成する

まず作業するためのディレクトリ（フォルダ）を作ります。

//cmd{
> mkdir new-project
> cd new-project
//}

ここで、ReVIEW記法で原稿を執筆するため、@<code>{first-chapter.re}を作ることにします。
同名のファイルをエディタで開き（新規作成し）、執筆を開始しましょう。

まず章のタイトルを書くところから始めます。（@<list>{first-project-content}）



//list[first-project-content][章タイトルを作る]{
= ReVIEWを用いて執筆を始める
//}



行の先頭に「=」とついています。
これは「章タイトル」を示すReVIEWの命令です。

命令を記述する際、全角文字と半角文字の違いについては注意してください。
ReVIEWでは、すべての命令は半角文字で入力します。
他のマークアップ言語と同様、ReVIEWは全角の「＠」を半角の「@」と同じようには処理してくれません。

タイトルを記述したファイルをHTML形式にコンパイルしてみましょう。

@<code>{review-compile}はREVIEW文法で書かれた原稿を指定されたフォーマットへ変換するコマンドです。
@<code>{--target html}と続けて指定することで、HTML出力をするよう指定します。

//cmd{
> review-compile --target html new-project.re
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1//EN" "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xmlns:ops="http://www.idpf.org/2007/ops" xml:lang="ja">
<head>
  <meta http-equiv="Content-Type" content="text/html;charset=UTF-8" />
  <meta http-equiv="Content-Style-Type" content="text/css" />
  <meta name="generator" content="ReVIEW" />
  <title>ReVIEWを用いて執筆を始める</title>
</head>
<body>
<h1><a id="h1"></a>第1章　ReVIEWを用いて執筆を始める</h1>
</body>
</html>
//}

標準出力にHTMLが出力されています。

HTMLを直接読んでもどういう見た目になるのか分かりづらいので、ブラウザで出力結果を見るために@<code>{test.html}に一旦保存します。

//list[redirecting-to-file][ファイルにリダイレクトする]{
> review-compile --target=html new-project.re > test.html
//}

このファイルを、Google Chromeで開くと、@<img>{output-1}のような出力が出てきます。



//image[output-1][最初の出力]{
//}

次に本文を書いてみましょう。
本文は2つ段落で構成します。
空行をはさむと別の段落になります。

//list[adding-sentences][二つの段落を構成する]{
= ReVIEWを用いて執筆を始める
本章ではReVIEWを用いて原稿を書いていく過程を紹介します。

読者がUNIX系OS上でコマンドやエディタの操作がある程度出来ることを仮定しています。
//}

これをコンパイルすると@<img>{output-2}のようになります。

//image[output-2][段落を足す]{
//}

節のタイトルを@<code>{==}を用いて足してみます。

//list[adding-clause][節を足します]{
= ReVIEWを用いて執筆を始める
本章ではReVIEWを用いて原稿を書いていく過程を紹介します。

読者がUNIX系OS上でコマンドやエディタの操作がある程度出来ることを仮定しています。

== プロジェクトを作成する
//}

結果は@<img>{output-3}の通りです。

//image[output-3][節を足す]{
//}

原稿をReVIEW記法でマークアップしながら、@<code>{review-compile}を繰り返し、「HTMLでおおまかな見栄えを確認する」を繰り返しおこないます。

=== 随時コンパイルしながら原稿を執筆する

脱線します。この項は無視して頂いて構いません。@<fn>{this_is_section}

//footnote[this_is_section][ちなみに@<code>{===}で「章」「節」に続く次の見出しである「項」を記述できます。この「項」のタイトルは「@<code>{=== 随時コンパイルしながら原稿を執筆する}」と記述することで作られています。]

執筆中、何度もコンパイルしながら内容をブラウザで確認することを考えると、ファイルをブラウザから開くのは面倒です。
出来れば、出力したら自動的にブラウザでそれを開いて欲しいですね。
筆者の環境（Linux）でこれを達成するためには、例えば以下のようにコマンドを実行します。

//list[easy-automation][LinuxでGoogle Chromeを用いて出力を即座に見る例]{
> review-compile --target html new-project.re > test.html; google-chrome test.html
//}

または別の方向性として、エディタでセーブするときにHTMLを出力させる、ということも思いつきます。
例として、vimというエディタで、ファイルを保存するたびにHTMLファイルを生成する、というハックがTechBoosterの筆者内で共有されたことがあります。（@<list>{review-with-vim}）

//list[review-with-vim][vimで原稿を保存した時にHTMLを自動で生成する。.vimrcに書く。]{
au BufWritePost *.re silent execute
\ '!review-compile --target html ' . expand('<afile>:.')
\ . ' > ' . expand('<afile>:p:h') . '/html_m/'
\ . expand('<afile>:t:r') . '.html'
//}

これは、例えば@<code>{/opt/new-project/}ディレクトリで@<code>{new-project.re}というファイルを編集中なら、以下のコマンドをファイルの保存の度に手動で実行することとほぼ同じ効果を持ちます。@<fn>{describe-it}

//cmd{
> review-compile --target html new-project.re > /opt/new-project/html_m/new-project.html
//}

こういった最適化にハマると原稿どころではなくなるのでここまでにしますが、ツールに習熟すると良いこともある事実は、覚えておいて良いかもしれません。

//footnote[describe-it][現在編集しているファイルをセーブした際（@<code>{BufWritePost}イベント時）に、そのファイルが@<code>{*.re}という正規表現にマッチした場合、自動的に@<code>{execute}以降に指定された命令をvimが実行します。@<code>{'!'}が@<code>{review-compile}という文字列の前にあるため、vimは@<code>{review-compile}という文字列をシェル上で実行されるべき外部のコマンドと解釈します。@<code>{review-compile}に渡される引数ですが、@<code>{expand()}は中に記述された文字列をルールとしてファイル名やらパス名に変換するvim内の関数です。これによって生成される文字列とその他の文字列を「@<code>{.}」で連結しています。@<code>{expand('<afile>:.')}は「現在開いているファイルの名前を実行ディレクトリからの相対パスで表現する」という意味、@<code>{expand('<afile>:p:h')}は「現在開いているファイルのフルパス（@<code>{:p}の機能）から最後のコンポーネントすなわちファイル名自体を削除（@<code>{:h}）する」という意味で、要はファイルのあるディレクトリを示します。@<code>{expand('<afile>:t:r')}は逆に最後のコンポーネント（@<code>{:t}）の拡張子を削除したもの（@<code>{:r}）になります。]

#@# muoたそに確認モトメル必要あり。

== 文を修飾する

UNIX環境についての注意書きは本文ではなく脚注に記載したくなったとします。
ここで登場するのが@<code>{＠<fn>}と@<code>{//footnote}です。

//list[use-footnote][脚注を導入する]{
 = ReVIEWを用いて執筆を始める
 本章ではReVIEWを用いて原稿を書いていく過程を紹介します。＠<fn>{assume_unix_experience}

 //footnote[assume_unix_experience][読者がUNIX系OS上でコマンドやエディタの操作がある程度出来ることを仮定しています。]

 == プロジェクトを作成する
//}

@<code>{assume_unix_experience}というキーワードを用いて、実際の脚注と、それにユーザを誘導する印との対応関係を記述します。
なお、ReVIEW記法全体を通じてこういった「@<code>{＠<"命令">}」や「@<code>{//"命令"}」といった命令が頻繁に登場します。

もう少し書き進めて、コマンドの実行例を紹介したい段階になったとします。コマンド実行例のための命令「@<code>{//cmd}」を使用してみます。


//list[use_cmd][//cmdを用いる]{
 == プロジェクトを作成する
 まず作業するためのディレクトリ（フォルダ）を作ります。
 //cmd{
 > mkdir new-project
 > cd new-project
 //}
//}


ファイルの内容を表示するために、@<code>{//list}を用いてみます。
listというと「箇条書き」のようなものを想像しますが、ここでのlistは「プログラムリスト」「ソースコード」のようなニュアンスです。


//list[use_list][//listを用いる]{
 == プロジェクトを作成する
 まず作業するためのディレクトリ（フォルダ）を作ります。
 //cmd{
 > mkdir new-project
 > cd new-project
 //}

 ここで、ReVIEW記法で原稿を執筆するため、first-chapter.reを作ることにします。
 同名のファイルをエディタで開き（新規作成し）、執筆を開始しましょう。
 
 まず章のタイトルを書くところから始めます。（＠<list>{first-project-content}）
 
 //list[first-project-content][章タイトル]{
 = ReVIEWを用いて執筆を始める
 //}
//}


文中に「first-chapter.re」とあるのですが、これはファイル名です。
プログラムのソースコードを文中に引用するような、若干異なるフォント（等幅フォント）等で表示して欲しいと考えたとします。
ReVIEWでは「＠<code>」命令によって、文中にそういった修飾を行うことができるので、今回はこれを用いてみます。

//list[use_code][＠<code>を使う]{
 ここで、ReVIEW記法で原稿を執筆するため、＠<code>{first-chapter.re}を作ることにします。
 同名のファイルをエディタで開き（新規作成し）、執筆を開始しましょう。
//}

既にお気づきかもしれませんが、本章の例は本章の本文を執筆する際に使ってきたものが元になっています。
記法についても同様です。

ただし、解説していない記法もあります。
たとえば、本文冒頭は（少なくともPDF出力において）他の本文の文面と段落の構成方法が変わっています。
いわゆる「リード文」のためのReVIEW記法を使っているからです。

また、他の章を参照する際、その章の番号を調べて「第○章」と書いていては、章構成が変わった時に対応できません。
そのため、本章の原稿には章番号は直接書かれていません。
代わりにファイルの章番号を埋め込むReVIEWの命令を用いています。

もし興味があれば、@<chap>{markup}を参照するなどして、これらを達成するReVIEW記法を調べてみてください。

書きたい内容を決めて、ReVIEW記法で記述して、HTMLで出力を大まかに確認する、というサイクルについて紹介しました。
執筆の例についてはここで止め、実際にHTML以外の書籍データを作成してみましょう。

== PDFに変換する

紙の同人誌として出版する場合に入稿フォーマットとして@<kw>{PDF, Portable Document Format}が使われることがあります。
そこで、ここまでで記述した原稿から、HTMLではなくPDF出力してみましょう。

PDF出力のためには外部ツールである@<tt>{TeX Live}が必要です。
インストールされているかを確認する一つの方法として、例えば以下のようなコマンドを実行します。

//cmd{
> platex --version
e-pTeX 3.1415926-p3.3-110825-2.4 (utf8.euc) (TeX Live 2012/Debian)
kpathsea version 6.1.0
ptexenc 1.3.0
Copyright 2012 D.E. Knuth.
There is NO warranty.  Redistribution of this software is
covered by the terms of both the e-pTeX copyright and
the Lesser GNU General Public License.
For more information about these matters, see the file
named COPYING and the e-pTeX source.
Primary author of e-pTeX: D.E. Knuth.
//}

バージョンが出力されれば準備万端ということはありませんが、エラーが出るようであれば@<tt>{TeX Live}の準備が出来ていないかもしれません。
@<chap>{how_to_install}を再確認してください。

@<code>{review-pdfmaker}を実行するにはもう少し準備が必要です。
PDFで出力するために必要な「本のタイトル」や「筆者名」を記述するためのYAMLファイルを用意します。

ここではとりあえず、ReVIEWのRuby実装が提供しているYAMLファイルをそのまま使って見ることにしましょう。

//cmd{
> wget https://raw.github.com/kmuto/review/master/doc/sample.yaml
--1982-06-16 16:59:02--  https://raw.github.com/kmuto/review/master/doc/sample.yaml
raw.github.com (raw.github.com) をDNSに問いあわせています... 103.245.222.133
raw.github.com (raw.github.com)|103.245.222.133|:443 に接続しています... 接続しました。
HTTP による接続要求を送信しました、応答を待っています... 200 OK
長さ: 2864 (2.8K) [text/plain]
`sample.yaml' に保存中

100%[==================================>] 2,864       --.-K/s 時間 0s      

2101-12-04 18:19:23 (17.0 MB/s) - `sample.yaml' へ保存完了 [2864/2864]
> cat sample.yaml
# review-epubmaker向けの設定ファイルの例。
# yamlファイルをReVIEWファイルのある場所に置き、
# 「review-epubmaker yamlファイル」を実行すると、<bookname>.epubファイルが
# 生成されます。
# このファイルはUTF-8エンコーディングで記述してください。

# ブック名(ファイル名になるもの。ASCII範囲の文字を使用)
bookname: review-sample
# 書名
booktitle: ReVIEW EPUBサンプル

... （以下省略）
//}

得られた@<code>{sample.re}を用いて@<code>{review-pdfmaker}を実行します。

//cmd{
> review-pdfmaker sample.yaml
compiling new-project.tex
No such directory - /tmp/new-project/sty
This is e-pTeX, Version 3.1415926-p3.3-110825-2.4 (utf8.euc) (TeX Live 2012/Debian)
 restricted \write18 enabled.
entering extended mode
(./book.tex
pLaTeX2e <2006/11/10> (based on LaTeX2e <2011/06/27> patch level 0)
Babel <v3.8m> and hyphenation patterns for english, dumylang, nohyphenation, pi
nyin, thai, loaded.
(/usr/share/texlive/texmf-dist/tex/platex/jsclasses/jsbook.cls
Document Class: jsbook 2010/03/14 okumura
) (/usr/share/texlive/texmf-dist/tex/platex/japanese-otf-uptex/otf.sty
(/usr/share/texlive/texmf-dist/tex/platex/japanese-otf/ajmacros.sty))
(/usr/share/texlive/texmf-dist/tex/latex/graphics/color.sty

..（省略）

(./book.aux) )
Output written on book.dvi (2 pages, 1436 bytes).
Transcript written on book.log.
book.dvi -> book.pdf
[1][2]
3250 bytes written
//}

ここで大量のログ出力されますが、正常です。
内部で@<tt>{TeX Live}のコマンド等を実行する際、例え1文字の原稿をコンパイルしてPDFにするときにも多くのログが表示されます。
大半はTeX絡みの出力です。

コマンド実行が終了したらPDFが出来たかを確認します。

//cmd{
> ls *.pdf
review-sample.pdf
//}

今回は@<code>{review-sample.pdf}というファイルが出力されています。
なお、使用したYAMLファイル（今回は@<code>{sample.yaml}）の、@<code>{bookname}という設定に応じてこのファイル名は変わります。

さて、PDFリーダで見てみますと……

//image[pdf-1][表紙っぽいものは出た……が、表紙と目次の2ページしかない][scale=0.15]{
//}

自分の原稿が取り入れられていません(´・ω・`)

=== catalog.ymlを導入する

ここまでで行なってきたことを振り返ってみます。

 * new-project/ ディレクトリを作成
 * その配下に@<code>{new-project.re}を作成
 * @<code>{review-compile}でHTMLを出力しつつ原稿を執筆
 * @<code>{sample.yaml}を取得
 * @<code>{review-pdfmaker sample.yml}を実行
 * @<code>{new-project.re}が生成されたPDFに@<strong>{含まれていない}ことを確認

この問題は、@<code>{new-project.re}というファイルが、本を構成するファイルとして認識されていないために起こります。
例えば仮に@<code>{second-chapter.re}というファイルで「第二章」を作った場合には、どちらが先なのかも指定しなければなりません。

そういった指定を行うため、@<code>{catalog.yml}というファイルを新たに作成します。
そして、そのファイルに、本に収録するReVIEW形式のファイルを記述します。

//cmd{
> ls
catalog.yml  first-chapter.re  review-sample.pdf  sample.yaml
> cat catalog.yml
CHAPS:
  - first-chapter.re
> rm review-sample.pdf
> review-pdfmaker sample.yaml
（出力省略）
//}

これで章として認識されるはずです(｀・ω・´)@<img>{pdf-2}

//image[pdf-2][原稿を取り入れた後のPDFの例][scale=0.15]{
//}

現時点ではタイトルがお好みのものではないかと思います。
@<code>{sample.yaml}を編集して、自著の書籍名に変えるといった作業を行います。

=== catalog.ymlにおけるPREDEF、POSTDEF、APPENDIX、PARTの解説

@<code>{catalog.yml}は本文の章構成を決めるファイルで、ReVIEWでは「カタログファイル」と呼びます。
また、@<code>{catalog.yml}には、@<code>{CHAPS}を含め、書籍を構成するファイルをそれぞれ記述します。

本章で詳しくは紹介しませんが、カタログファイルに記述するものが他にもあるのでここで紹介します。

 * @<code>{PREDEF}は前付けに用いるReVIEWファイルを列挙します
 * @<code>{POSTDEF}は後付けに用いるReVIEWファイルを列挙します
 * @<code>{APPENDIX}は付録に用いるReVIEWファイルを列挙します
 * @<code>{PART}は書籍に「部」を導入するときに使われます。

しっかりした書籍を作る際にはこれらを駆使することになりますが、本章を読まれている時点では「そういうものも存在する」くらいの理解で良いと思います。
@<code>{CHAPS}のみうまく扱えるようにしましょう。

#@# この3ファイルの活用法はこの本のどこで詳説されるんだろう

== EPUBファイルを作る

次に電子書籍のおいて一般的なEPUB形式の出力を試します。
まず、EPUB作成に必要な@<code>{zip}コマンドが利用できることを確認します。

//cmd{
> zip -L
Copyright (c) 1990-2008 Info-ZIP.  All rights reserved.

For the purposes of this copyright and license, "Info-ZIP" is defined as
the following set of individuals:

.. （以下省略。ライセンスが表示されています）
//}

YAMLファイルを指定して@<code>{review-epubmaker}コマンドを実行します。

//cmd{
> review-epubmaker sample.yaml
  adding: mimetype (stored 0%)
  adding: META-INF/container.xml (deflated 29%)
  adding: OEBPS/review-sample.html (deflated 46%)
  adding: OEBPS/review-sample.opf (deflated 54%)
  adding: OEBPS/first-chapter.html (deflated 40%)
  adding: OEBPS/top.html (deflated 44%)
  adding: OEBPS/stylesheet.css (deflated 3%)
  adding: OEBPS/review-sample.ncx (deflated 48%)
> ls *.epub
review-sample.epub
//}

今回は、Google Chromeの拡張として利用できる電子書籍リーダ「Readium@<fn>{about_readium}」で、出来上がった電子書籍ファイル「@<code>{review-sample.epub}」を開いてみましょう。（@<img>{epub-1}）

//image[epub-1][作成したEPUBファイルをReadiumで開いた例]

//footnote[about_readium][@<href>{http://readium.org/}]

== おわりに

本章ではReVIEWを用いて原稿を執筆する例を紹介しました。
プロジェクト作成からPDF・EPUBの作成まで、出来るようになったかと思います。

実際の執筆作業を続けていく上では、ReVIEWの記法や細かい点について、より詳細に理解する必要が発生します。
そのようなとき、本書の他の章が参考になるはずです。

 * 記法の詳細は@<chapref>{markup}にあります。
 * 出力の見栄えについては@<chapref>{style_customize}で詳述されています。
 * ReVIEWコマンドの詳細は@<chapref>{commands}にあります。
 * 他のReVIEW利用例を見てみたい場合、@<chapref>{yanzm}を参照するのが良いでしょう。
 * ReVIEW記法の技術的理解をひたすら深めたい方は@<chapref>{vvakame}が参考になるはずです。

各章は独立していますので、必要に応じてトピックを選んで読むのが良いでしょう。

それでは、ReVIEWで素敵な進捗を。