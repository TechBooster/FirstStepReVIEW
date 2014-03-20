= コマンド解説

//lead{
本章ではReVIEWに付属するコマンドを紹介します。
//}

== review-compile

@<code>{review-compile}はReVIEWファイル1つを変換して@<code>{--target}オプションで指定するフォーマットに変換します。

最も簡単な例として、HTMLを出力する例を@<list>{review-compile-example-html-1}に示します。
入力は@<chap>{introduction}の冒頭で示した例と同じです。

//list[review-compile-example-html-1][review-compileでHTMLを出力する例。]{
> review-compile --target=html amedama.re
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1//EN" "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xmlns:ops="http://www.idpf.org/2007/ops" xml:lang="ja">
<head>
  <meta http-equiv="Content-Type" content="text/html;charset=UTF-8" />
  <meta http-equiv="Content-Style-Type" content="text/css" />
  <meta name="generator" content="ReVIEW" />
  <title>Google Drive APIを使ってファイルをダウンロードする</title>
</head>
<body>
<h1><a id="h38"></a>第38章　Google Drive APIを使ってファイルをダウンロードする</h1>
<p>本章では、PythonスクリプトからGoogle Driveに保存されているファイルを取得する方法を紹介します。Androidとは直接関係ありませんが、同様のAPIをAndroid上で利用する際に参考になるかもしれません。</p>

<h2><a id="h38-1"></a>38.1　収録されている背景</h2>
<p>『Effective Android』同人誌版の執筆が行われていた頃、原稿はGoogle Drive上で管理されていました。一部の技術者の希望によりgitも用いる運用に途中から切り替えたのですが、全員がgitを利用できるわけではないため、原則Google Driveにファイルをアップロードとし、gitは希望者が選択して用いる、という体制になりました<a href="#fn-not_used" class="noteref">*1</a>。</p>
<div class="footnote"><p class="footnote">[<a id="fn-not_used">*1</a>] 本稿執筆時点ではすでにこの体制は終了しています。</p></div>
<p>このとき、管理者がGoogle Drive上のファイルを手動でダウンロードしてgitプロジェクトに取り込んでいると聞き、私はその作業を自動化できるかもしれないと考えました。</p>
<p>Google Drive APIとそのSDKはGoogleから無料で提供されていました。少し調べた結果、今回の目標のためにはそれを使えばよいことが分かりました。</p>
<ul>
<li>What Can You Do with the Drive SDK?<br /><?dtp tab ?>
<a href="https://developers.google.com/drive/about-sdk"
 class="link">https://developers.google.com/drive/about-sdk</a>
</li>
</ul>
... (以下省略)
//}

HTML向け出力は、執筆時に「大まかにどのような出力になるのか」を確認するためによく使われます。
その他にもプレーンテキスト形式にする@<code>{--target=text}、PDFを出力するために必要なTeX形式のファイルを出力する@<code>{--target=latex}、軽量マークアップ言語であるMarkdown形式を出力する@<code>{--target=markdown}などがあります。

//footnote[target_epub_is_not_for_epub][@<code>{--target=epub}は圧縮してEPUB形式とする前のただのHTMLを出力します。]

読者の環境で@<code>{--target}で指定できるフォーマットを調べるには、ReVIEW本体のインストール先にある@<code>{lib/review/???builder.rb}というファイル名のファイルを確認するのが早道です。

//list[supported-target][ReVIEWが対応している出力を確認]{
> ls lib/review/*builder.rb
lib/review/builder.rb        lib/review/ewbbuilder.rb    lib/review/idgxmlbuilder.rb
lib/review/latexbuilder.rb   lib/review/textbuilder.rb   lib/review/epubbuilder.rb
lib/review/htmlbuilder.rb    lib/review/inaobuilder.rb   lib/review/markdownbuilder.rb
lib/review/topbuilder.rb
//}

もっとも、対応する出力形式の多くはReVIEW開発者らが仕事上利用するものであったりするため、執筆時には@<code>{--target=html}を指定する機会が多いと思われます。

@<code>{--check}を指定すると、結果は出力せず、そのフォーマットで入力したファイルが正しく変換出来るかを確認できます。
例えば、@<code>{footnote}と@<code>{fn}で対応がとれているべき場所でとれていない場合、その旨が表示されます。
これもまた執筆中にエラーを前もって避けるために便利です。@<fn>{for_pdf}

#@# レビュー by わかめ caption書こう
#@# レス by あめ玉 書いた

//list[unpaired-result][＠<fn>と対応する//footnoteがない場合に発生するエラー]{
> review-compile --check --target=html amedama.re
amedama.re:11: error: ReVIEW::KeyError
//}

#@# レビュー by わかめ 各.reに対して逐次行うとー みたいな、総当りで頑張るのが正義なんだよ！感のあるワードがほしい
#@# レス by 全チェックするコマンドくれ的な話として書いた。

//footnote[for_pdf][@<code>{review-pdfmaker}にはこの機能がない一方、前述した通り@<code>{review-compile}では直接はPDFを出力しません。対策として@<code>{review-compile --check --target=latex}とすると、PDFで問題が起こる前に修正できます。出来れば@<code>{review-pdfmaker}を使って対象とする全てのファイルに対してチェックを行える何かが欲しいところです。]

#@# レビュー by わかめ デバッグ用途 とかのほうがいいかなぁ「」の意味がなくなるけど
#@# レス by あめ玉 読者対象者がプログラマ隣接してるから「」いらねーじゃね、ということで消すことにする。

出力されたhtmlを、執筆時のデバッグ用途としてではなく見栄えの良い公開用ファイルにすることもできます。
@<code>{--yaml=(ファイル名)}でReVIEWプロジェクトの設定を読みこませることでスタイルを変更するとよいでしょう。
なお、@<code>{--help}を指定すると、ファイルを読み込んで変換する代わりに対応するオプションの一覧が表示されます。
本章で説明されていないオプションも多々あるので、必要に応じて参照してください。

=== 注意: @<code>{review-compile}ではそのままPDFとEPUBは生成できない

現時点では@<code>{review-compile}からは直接PDFとEPUB形式のファイルを生成することはできません。@<fn>{target_epub_is_not_for_epub}
後述する@<code>{review-pdfmaker}と@<code>{review-epubmaker}をそれぞれ利用してください。

@<code>{review-compile}は主に単一のファイルに対して操作を行う一方、@<code>{review-pdfmaker}と@<code>{review-epubmaker}はReVIEWプロジェクト全体を対象とするため、用途も異なります。
仮に執筆途中のReVIEWファイルのみ、PDFによるフォーマットを確認したい場合、自身でTeX形式から生成する、あるいは逆に全体を@<code>{review-pdfmaker}で生成したあと、該当する章を@<code>{pdktk}等のコマンドで切り出してください。

== review-pdfmaker

@<code>{review-pdfmaker}はそのプロジェクトのPDFを生成します。
引数としてYAMLファイル（@<code>{config.yml}）を一つ指定します。

#@# レビュー by わかめ xpdf is 何？ (Macだとopen book.pdf すると僕の場合Preview.appで開かれるのでそのまま見る)
#@# Linux でpdf見るコマンド。acroreadって書くより原理主義の信頼を得られるのだ！（弱気
#@# 面倒なので開く方は省略。これでもきっとくうきよめるよね！

//list[review-pdfmaker-example-1][review-pdfmakerの実行例]{
> review-pdfmaker config.yml
(出力省略)
//}

YAMLファイルには本のタイトルや筆者名といった本のメタデータとなる設定を記述しておきます。
その設定の一つ「@<code>{bookname}」が出力されるPDFに対応しています。

@<code>{bookname}で「book」となっている場合、ReVIEWは「@<code>{book-pdf/}」ディレクトリに、途中過程で生成されるファイルを保存した上で、最終的に「book.pdf」を自身のディレクトリに保存します。
仮にこれらのファイル・ディレクトリがすでに存在している場合、ReVIEWはコマンドの実行を中止します。

//list[review-pdfmaker-example-2][すでにPDFを一度作成したあとに再度review-pdfmakerしたときの実行例]{
> review-pdfmaker config.yml
/opt/review/bin/review-pdfmaker:57:in `mkdir': File exists - ./book-pdf (Errno::EEXIST)
        from /opt/review/bin/review-pdfmaker:57:in `main'
        from /opt/review/bin/review-pdfmaker:219:in `<main>'
//}

再度コンパイルする際には、まず手動でPDF（book.pdf）と中間ファイルを収めるディレクトリ（book-pdf/）を削除してから、再度@<code>{review-pdfmaker}を実行します。

@<code>{review-pdfmaker}は内部で@<code>{review-compile --target=latex}を行ったあとに@<code>{platex}や@<code>{dvipdfmx}のようなTeX形式のファイルからPDFへ変換するReVIEW外部のコマンドを実行します。
ReVIEWの外部のコマンドを実行している際には外部のログがそのまま標準出力や標準エラー出力に反映されるため、面食らうかもしれません。

=== 脱線: Rakefile で自動化

コンパイル前にbook.pdf等を手動で削除する作業は少々面倒なため、@<code>{Rakefile}@<fn>{about_rakefile}に詳しい人はしばしば以下のような設定を書いています。

//footnote[about_rakefile][今回のように典型的な作業を自動化するツールの一つです。後述する@<code>{review-init}でも生成されています。]

//list[rakefile-example-1][Rakefileにbook.pdfとbook-pdfの削除を行わせてしまう一例]{
task :default => :pdf

desc 'generate PDF file'
task :pdf => "book.pdf"

SRC = FileList['*.re'] +  ["config.yml"]
file "book.pdf" => SRC do
  sh "rm -f book.pdf"
  sh "rm -rf book book-pdf"
  sh "review-pdfmaker config.yml"
end
//}

このように記述しておくと、@<code>{rake}コマンドは関連するReVEWファイルや@<code>{config.yml}に変更があった際に限って削除と@<code>{review-pdfmaker}の実行を行います。

=== 執筆時の注意点

@<code>{review-pdfmaker}は、その書籍に含まれるReVIEWファイルに問題があっても、一見正常にPDFを出力することができます。
この場合、コマンド自身は「成功」と報告するのですが、該当する章のデータが勝手に抜け落ちている、という事態につながります。

最も単純な事例は@<chap>{first_review_project}で紹介した@<code>{CHAPS}での指定を忘れることです。
また、一部の構文エラーについても、そのファイルがなかったこととして、PDFが生成されてしまいます。

これは、複数のReVIEWファイルを用いて原稿執筆している際に若干厄介な問題です。
特に執筆後半では、見栄えの調整のために@<code>{review-compile}よりも頻繁に@<code>{review-pdfmaker}等を実行することがあるのですが、@<code>{review-compile}エラーで中止する代わりに、コマンドはエラーが発生した章を無視してPDFを生成します。

対策として、執筆時には@<code>{review-compile --target=latex --check}を実行して執筆中の原稿単体で発生している問題を排除してから@<code>{review-pdfmaker}を実行することをおすすめします。

章がまるまる抜け落ちることを利用してページ数が減っていないか確認することも出来ます。
参考まで、Linuxの@<code>{pdftk}コマンドでページ数を見る例を示します。

//cmd{
> pdftk book.pdf dump_data_utf8 | grep NumberOfPages
NumberOfPages: 103
}

#@# レビュー by わかめ 一番簡単な判別方法として、生成されたPDFのページ数が明らかに減っている場合、途中で問題が発生してどこかの章がまるまる無視されてしまったものと判断できます みたいなのほしい
#@# それなー。普通の人（1章の本くらいの人）はページ数見るよりもチャプター消滅してることで気づくんじゃないかなーとか。一応足しとくけど。

== review-epubmaker

@<code>{review-pdfmaker}同様、@<code>{review-epubmaker}はプロジェクトのメタデータとなるYAMLファイルを引数としてEPUBファイルを生成します。

//list[review-epubmaker-example-1][review-epubmakerの例]{
> review-epubmaker config.yml
(出力省略)
> file book.epub
book.epub: EPUB ebook data
（電子書籍リーダに読み込ませることで内容を確認出来る）
//}

@<code>{review-pdfmaker}同様、参照するYAMLファイル内の@<code>{bookname}を元にして出力されるファイル名が決定されます。

また、コンパイルに関わる注意点も@<code>{review-pdfmaker}と同様です。
PDFとは異なりEPUBでページ数をチェックすることはできませんが、EPUBは実質zip圧縮されたHTMLファイルの塊であるという点を利用して、@<code>{unzip -l}等で自身の原稿ファイルが最終的なEPUBファイルに含まれているかをチェックすることは出来るでしょう。

#@# レビュー by わかめ う、す、いー！！ review-pdfmakerと同じ注意点を引き継ぎます。とかで良さそう？
#@# 前の章でもそうだけど、書いてるとどうしてもこっちは薄くなるんだよなー……

== review-preproc

引数に取ったファイル内にある、@<code>{#@mapfile}、@<code>{#@maprange}、@<code>{#@mapoutput}といったタグを認識し、それぞれのタグの要求した出力を元のファイルに埋め込みます。

例として、プログラミング言語Javaのバージョン情報を埋め込む例を見てみます。

#@# レビュー by わかめ exit が != 0 の場合preprocを中断するみたいなクソ仕様だったと思うのでコンパイラのエラーメッセージを紙面に出力する用途にはHackが必要かも
#@# レス えーそれ書くのかー？

//list[mapoutput_example][#@mapoutputを用いた実例]{
 //cmd{
 #@mapoutput(java -version 2>&1)
 #@end
 //}
//}

この命令だけを含むファイル（@<code>{sample.re}とします）に対して@<code>{review-preproc}を実行すると、例えば以下のとおりになります。

//cmd{
 > review-preproc sample.re
 //cmd{
 #@mapoutput(java -version 2>&1)
 java version "1.6.0_27"
 OpenJDK Runtime Environment (IcedTea6 1.12.6) (6b27-1.12.6-1~deb7u1)
 OpenJDK 64-Bit Server VM (build 20.0-b12, mixed mode)
 #@end
 //}
//}

コマンドの実行結果が@<code>{review-preproc}で挿入されています。
なお、@<code>{-r}オプションを用いた場合、上述した例のように標準出力に表示される代わりに元のファイルの該当部分を上書きします。

//cmd{
 > cat sample.re
 //cmd{
 #@mapoutput(java -version 2>&1)
 #@end
 //}
 > review-preproc -r sample.re
 > cat sample.re
 //cmd{
 #@mapoutput(java -version 2>&1)
 java version "1.6.0_27"
 OpenJDK Runtime Environment (IcedTea6 1.12.6) (6b27-1.12.6-1~deb7u1)
 OpenJDK 64-Bit Server VM (build 20.0-b12, mixed mode)
 #@end
 //}
//}

@<code>{#@mapfile}、@<code>{#@maprange}、@<code>{#@mapoutput}はいずれも、ReVIEWファイルの外部を参照するための命令です。
いずれもその命令開始とセットで@<code>{#@end}を別の行に記述する必要があります。

#@# レビュー by わかめ table記法として正しくないお。\t区切り ---- でヘッダとボデーの区切り
#@# なおしたったー

//table[files][生成されるファイルと役割]{
コマンド名と引数  意味
----
mapoutput(コマンド) コマンドを実行して、その出力結果を展開する。
mapfile(ファイル名)  ファイルの内容全てをその場に展開する。
maprange(ファイル名, 範囲名)  ファイル内の範囲をその場に展開する。
//}

プログラミング言語の解説等を行なっている場合、サンプルとして提供するソースコードの一部を本文に挿入し、サンプルのソースコードの修正と併せて本文を動的に変更したいといったことがあります。
@<code>{review-preproc}はそういったときに力を発揮するコマンドです。

サンプルと併せてコマンドラインツール自体もアップデートしていく可能性があります。
例えばJavaのバージョンが手元でアップデートされたとします。
通常、手動で埋め込むべきところを、以下のようにアップデートすることができます。

#@# レビュー by わかめ おっおっおっ -r 使うと間に埋め込まれて再実行すると更新できるのか！知らなかった！そういう意味か！今まで commands-post.re とか作ってたわ！！クッソ便利やん！！！はわわわー
#@# 再発見の旅！

//cmd{
 > cat sample.re
 //cmd{
 #@mapoutput(java -version 2>&1)
 java version "1.6.0_27"
 OpenJDK Runtime Environment (IcedTea6 1.12.6) (6b27-1.12.6-1~deb7u1)
 OpenJDK 64-Bit Server VM (build 20.0-b12, mixed mode)
 #@end
 //}

 (ここでJavaのバージョンをアップデートした)

 > review-preproc -r sample.re
 > cat sample.re
 //cmd{
 #@mapoutput(java -version 2>&1)
 java version "1.7.0_25"
 Java(TM) SE Runtime Environment (build 1.7.0_25-b15)
 Java HotSpot(TM) 64-Bit Server VM (build 23.25-b01, mixed mode)
 #@end
 //}
//}

@<code>{mapfile}はほぼ自明なので省略します。

@<code>{maprange}は名前の通りファイルの範囲を指定出来ます。
ただし、使い方が特殊です。

例えば、以下のようなファイルがあるとします

//list[example_file][例となるファイル]{
 #!/usr/bin/env python
 import os
 import sys

 if __name__ == "__main__":
     os.environ.setdefault("DJANGO_SETTINGS_MODULE", "project.settings")
     from django.core.management import execute_from_command_line
     execute_from_command_line(sys.argv)
//}

ここで@<code>{if}から始まる行とそれ以降3行を引用したいとします。
その場合、@<code>{maprange}は@<strong>{このファイルに対してマーカをセットすることを要求します}。

//list[use_maprange][maprangeを使うためにマーカをセット。ファイル名はtest.py]{
 #!/usr/bin/env python
 import os
 import sys

 #@range_begin(example)
 if __name__ == "__main__":
     os.environ.setdefault("DJANGO_SETTINGS_MODULE", "project.settings")
     from django.core.management import execute_from_command_line
     execute_from_command_line(sys.argv)
 #@range_end(example)
//}

この状態で、ReVIEWのファイルに以下を記述します。

//list[use_maprange_review_side][マーカをReVIEWのファイルで使う]{
 #@maprange(filename.py,example)
 #@end
//}

そこで@<code>{review-preproc}を用いると、マーカ範囲の内容がコピーされます

//list[use_maprange_review_side_result][内容がコピーされる]{
 #@maprange(filename.py,example)
 if __name__ == "__main__":
     os.environ.setdefault("DJANGO_SETTINGS_MODULE", "project.settings")
     from django.core.management import execute_from_command_line
     execute_from_command_line(sys.argv)
 #@end
//}

引用元のファイルを変更するため、状況によっては非常に使いづらい命令だと筆者は考えます。

特にプログラミング言語の著書を書くときには問題になるかもしれません。
現在の実装では、この行の先頭は必ず@<code>{#}です。
ReVIEWの本体が採用しているRuby言語ならまだしも、
例えばC・C++といった言語では@<code>{#}は全く別の意味を持ちますから、
おそらく引用元のファイルはコンパイルエラーを発生させるでしょう。
本末転倒です。

== review-init

@<code>{review-init}は、引数に指定された名前のディレクトリを作成し、その配下に新しいReVIEWプロジェクトを作成します。
作成されるディレクトリが存在していた場合エラーになります。
このコマンドは新規のプロジェクト作成時に利用できます。@<fn>{broken_in_11}

//footnote[broken_in_11][RubyGemsから取得できるバージョン1.0でこのコマンドはそもそも存在せず、1.1では@<code>{review-init}が動作しないことが確認されています。git版の執筆時点での最新版を用いて検証しています]

//cmd{
/tmp> ls new-project
ls: cannot access new-project: No such file or directory
/tmp> review-init new-project
/tmp> ls new-project
CHAPS  POSTDEF PREDEF Rakefile config.yml images layouts new-project.re sty
> review-init new-project
/tmp/new-project already exists.
//}

@<code>{review-init}で生成されるファイルは@<table>{files}の通りです。

//table[files][生成されるファイルと役割]{
ファイル名 役割
--------------
CHAPS 本の本文構成するReVIEWフォーマットのファイル(@<code>{.re})を記述する。
PREDEF  本の前付けとなるReVIEWフォーマットのファイル(@<code>{.re})を記述する。実例の章参照
POSTDEF 本の後付けとなるReVIEWフォーマットのファイル(@<code>{.re})を記述する。実例の章参照
Rakefile  コマンド実行の自動化を図るためのファイル。@<chap>{words}のRakefileの項を参照。
config.yml  このプロジェクトのメタデータ。@<chap>{style_customize}を参照。
images/ 本の画像を収めるディレクトリ
layouts/  <chap>{style_customize}を参照。
sty/  <chap>{style_customize}を参照。
（プロジェクト名）.re  サンプルのReVIEWファイル
//}

#@warn(実例の章はおそらく羊の原稿。何章であるかはチェックする必要あり)


原稿サンプルのファイル名のみ@<code>{review-init}の引数名に依存します。
また、CHAPSには@<code>{（プロジェクト名）.re}が含まれます。
このファイルを消す・その名前を変更する場合はCHAPSも同様に修正してください。

#@# レビュー by わかめ 節の頭にgem版ReVIEW(1.1.0)ではコマンドは存在しますが動作しません。GitHubのmaster/HEADを使うとこの記事の通りに利用できます。ていう補足いるっしょやー。
#@# かいたー

=== @<code>{review-init}を用いない初期化方法

執筆開始時にプロジェクトを作成する方法は何通りかあります。

 * @<code>{review-init}を用いる。
 * @<href>{https://github.com/takahashim/review-sample-book}を用いる。
 * 手動で各ファイルを用意する。
 * 自分用にカスタマイズ済の既存のプロジェクトから適宜コピーする。

現時点ではReVIEWを構成するファイルは数種類です。
それらが複雑に絡み合った依存関係を形成しているわけではありません。
手動でプロジェクトを構成しても、特別不都合が発生するわけでもありません。
実際、@<chapref>{first_review_project}ではReVIEWの構造を順番に説明出来るように手動の方法を採用しています。

個人個人で最適な方法を用いれば良いのではないかと筆者は考えます。

#@# レビュー by わかめ https://github.com/takahashim/review-sample-book に言及するべき？？(弱気)
#@# そうした

== その他のコマンド

=== review-epubmaker-ng

@<code>{review-epubmaker}と同様にEPUB形式のファイルを生成するコマンドです。
武藤氏による新しい実装が試みられている様子がありますが、今後旧実装と統合されてなくなる可能性もあります。
執筆をしたい人が敢えて利用する理由はありません。

#@# レビュー by わかめ まだ実用するには実装に対する知識が必要になるため、強く「やめとけ！」と言っておきます。みたいなのあってもいい
#@# かいた

=== review-vol

@<code>{review-vol}はReVIEWで書かれた原稿のファイルサイズや文字数や行数を一覧にして取得します。
引数は受け取りません。

//list[review-vol-example][review-volの出力例。原稿はEffective AndroidのC84版を使用]{
(原稿のあるディレクトリで)> review-vol
      1KB    332C    12L   1P preface ................. はじめに
      1KB    403C    15L   1P techbooster_member_introduction  サークル Techbooster 紹介
 1.   0KB      0C     0L   0P blank ...................
 2.   9KB   7240C   288L   9P yanzm ................... はやりのカード UI をちゃちゃっと作る
 3.  12KB   7345C   270L  12P kassy_kz ................ 引っ張って更新するListViewを作る（PullToRefresh）
 4.  10KB   3655C   126L  10P tommmmy ................. デザイナーもエンジニアも幸せになるAndroidアプリデザインの方法
 5.  13KB   6121C   170L  13P kazzz ................... Twitter BootstrapでレスポンシブWebデザインを試す
 6.  13KB   6054C   166L  13P keiji_ariyama ........... AndroidManifestマニアックス
 7.  17KB   9156C   224L  17P vvakame ................. Eclipseの設定ファイルを科学する
 8.  22KB  12777C   309L  22P zaki50 .................. apt対応プロジェクトの作り方
 9.  15KB   7530C   280L  15P esmasui ................. ContentProviderをアトミック操作する
10.  15KB   6589C   199L  15P yokmama ................. SQLiteDatabaseの悪（ワル）を使う
11.   7KB   3138C   100L   7P gabu .................... 5分でできるプッシュ通知
12.  14KB   8347C   354L  14P kei-i-t ................. GCMを使用してAndroid-PHPでPUSH通知を実装する
13.  15KB   9092C   330L  15P nkzn .................... 戦いはここにある！Maps v2で戦場を描け
14.  19KB   8614C   285L  19P namasode ................ vCard をちょこっと
15.   5KB   2863C    91L   5P androidsola ............. 残念なNFCタグに反応するAndroidを作る
16.  17KB  11992C   376L  17P lychee .................. ヘビーユーザに喜ばれそうなちょっとした対応
17.  14KB   7185C   235L  14P sys1yagi ................ SharedPreferencesにJavaオブジェクトを
18.  17KB   7067C   151L  17P muo_jp .................. オーディオ出力のパフォーマンスを改善するための足がかり
19.  17KB   7594C   208L  17P eaglesakura ............. AndroidのTextureViewとSurfaceViewの使い分け
20.  11KB   6007C   198L  11P kobashin ................ NavigationDrawerを使ってスライド式のメニューを実装する
21.   9KB   4161C   159L   9P muchiki0226 ............. Fragmentで実装するアニメーション付きカードUI
22.  19KB  12624C   458L  19P amedama ................. Google Drive API を使ってファイルを git プロジェクトに取り込む
23.   3KB   1033C    63L   3P contributer ............. コントリビュータ紹介
=============================
    281KB 156919C  5067L 281P
//}

#@# レビュー by わかめ TODO?
#@# なおしたー

@<code>{-P}オプションをつけると@<code>{PART}に記述されたパートと@<code>{PREDEF}、@<code>{POSTDEF}毎に結果を分解します。

//list[review-vol-P][review-vol -Pの出力例（Effective AndroidのC84版原稿を使用]{
> review-vol -P
      1KB    332C    12L   1P preface ................. はじめに
      1KB    403C    15L   1P techbooster_member_introduction  サークル Techbooster 紹介
    --------------------
      2KB    735C    27L   2P

Part 1
 1.   0KB      0C     0L   0P blank ...................
 2.   9KB   7240C   288L   9P yanzm ................... はやりのカード UI をちゃちゃっと作る
 3.  12KB   7345C   270L  12P kassy_kz ................ 引っ張って更新するListViewを作る（PullToRefresh）
 4.  10KB   3655C   126L  10P tommmmy ................. デザイナーもエンジニアも幸せになるAndroidアプリデザインの方法
 5.  13KB   6121C   170L  13P kazzz ................... Twitter BootstrapでレスポンシブWebデザインを試す
 6.  13KB   6054C   166L  13P keiji_ariyama ........... AndroidManifestマニアックス
 7.  17KB   9156C   224L  17P vvakame ................. Eclipseの設定ファイルを科学する
 8.  22KB  12777C   309L  22P zaki50 .................. apt対応プロジェクトの作り方
 9.  15KB   7530C   280L  15P esmasui ................. ContentProviderをアトミック操作する
10.  15KB   6589C   199L  15P yokmama ................. SQLiteDatabaseの悪（ワル）を使う
11.   7KB   3138C   100L   7P gabu .................... 5分でできるプッシュ通知
12.  14KB   8347C   354L  14P kei-i-t ................. GCMを使用してAndroid-PHPでPUSH通知を実装する
13.  15KB   9092C   330L  15P nkzn .................... 戦いはここにある！Maps v2で戦場を描け
14.  19KB   8614C   285L  19P namasode ................ vCard をちょこっと
15.   5KB   2863C    91L   5P androidsola ............. 残念なNFCタグに反応するAndroidを作る
16.  17KB  11992C   376L  17P lychee .................. ヘビーユーザに喜ばれそうなちょっとした対応
17.  14KB   7185C   235L  14P sys1yagi ................ SharedPreferencesにJavaオブジェクトを
18.  17KB   7067C   151L  17P muo_jp .................. オーディオ出力のパフォーマンスを改善するための足がかり
19.  17KB   7594C   208L  17P eaglesakura ............. AndroidのTextureViewとSurfaceViewの使い分け
20.  11KB   6007C   198L  11P kobashin ................ NavigationDrawerを使ってスライド式のメニューを実装する
21.   9KB   4161C   159L   9P muchiki0226 ............. Fragmentで実装するアニメーション付きカードUI
22.  19KB  12624C   458L  19P amedama ................. Google Drive API を使ってファイルを git プロジェクトに取り込む
23.   3KB   1033C    63L   3P contributer ............. コントリビュータ紹介
    --------------------
    280KB 156184C  5040L 280P
=============================
    281KB 156919C  5067L 281P
//}

複数のパートに分かれた著書の管理には便利です。@<fn>{maybe_latest}

//footnote[maybe_latest][『Effective Android』商業誌版はパートを分解しているため、review-vol -Pの利用価値が上がります。]

このコマンドが同人誌の執筆等で必要になるケースはないかと思われます。


=== review-index

現在のReVIEWディレクトリのインデックス情報を出力します。
主に編集者向けのコマンドです。

//list[review-index-example-1][review-indexの出力例。全章の情報を出力するため@<code>{-a}も指定している]{
> review-index -a
      1KB    332C    11L  はじめに (preface)
                      6L       1 内容について
      1KB    403C    13L  サークル Techbooster 紹介 (techbooster_member_introduction)
                     13L          1 サークル Techbooster 紹介
                      3L             1 第11章 / @kei_i_t
                      2L             2 第19章 / @kobashinG
                      3L             3 第20章 / @muchiki0226
                      3L             4 編集 / @mhidaka
 2.   9KB   7240C   285L  はやりのカード UI をちゃちゃっと作る (yanzm)
                     29L       1 カード UI に変更するアプリ
                     27L       2 背景色を設定する
                     48L       3 カード UI 用のレイアウトを作る
                    171L       4 カード UI 用に ListView を調整する
 3.  12KB   7345C   292L  引っ張って更新するListViewを作る（PullToRefresh） (kassy_kz)
                    130L       1 Twitter公式アプリ等で使われている更新方法
                      5L          1 ライブラリのダウンロード
                     68L          2 基本的な使い方
                     37L          3 カスタマイズ
                    159L       2 Gmailアプリ等で使われているパターン
                      6L          1 ライブラリのダウンロード
                     27L          2 基本的な使い方
                    117L          3 カスタマイズ
.. (以下省略)
//}

=== review-check, review-checkdeps, review-validate

この3コマンドについては、本稿執筆時点では動作確認できませんでした。
興味を持たれた方はぜひ調べてみてください。

#@# レビュー by わかめ TODO?
#@# 重要でもないのでけすかー。

#@# レビュー by わかめ --help 関連の出力がクッソ貧弱なので引数チートシートとかほしいな❤ pull reqして出るようにしろという節もある
#@# 正直本体直すべきだな……というか個人的には今のオプションでもちょっと足りないから敢えてお茶濁したい……
