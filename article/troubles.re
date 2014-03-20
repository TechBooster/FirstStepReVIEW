= トラブル集

== @<code>{review-init}がRubyGems版で壊れているとか古いとか

本著執筆時に筆者間で議論をしていたのですが、@<code>{review-init}に話が及んだ際、そもそも動作する環境としない環境があるということで議論が紛糾しました。

その時点のRubyGems版（1.1.0）では@<code>{review-init}が壊れているということが分かりました。

RubyGems版は開発者の方が時間があるときにgitの変更を送るそうですが、しばしば忙しいということでリリースが遅れるようです。

その関係もあってRubyGems版がしばしば最新の変化を取り落としているので、gitの最新版をなるべく利用するべき、という意見と、バージョンは本来作業中には固定であるべきで、unstableの最新を追うべきではないのだから、変更するよう頼み続けるべきだ、という議論がありました。

読者がReVIEWを利用する場合には、いずれにしても腹を括らねばなりません。

RubyGems版を利用しているならば最初にバージョンを確認しておきましょう。なにかのトラブルに巻き込まれた時のため、あるいは巻き込まれた後でも差し支えありません。

//cmd{
> gem list review
//}

大事なのはトラブルを解決しようという気力です@<fn>{mhidaka}。

//footnote[mhidaka][どうにもならない場合、Twitterで@mhidakaにメンションを送って相談すると解決の糸口が見つかるかもしれません]

== 「@<code>{===タイトル}」と原稿に書いたらReVIEWのコンパイルが止まらなくなった

//list[broken_title][コンパイルが止まらなくなった例]{
===Test
//}

お分かり頂けるだろうか……？@<fn>{bug_213}

//footnote[bug_213][@<href>{https://github.com/kmuto/review/issues/213}]

世の中の書籍執筆の例に漏れずTechBoosterでも「継続的インテグレーション」的なサーバというのはありまして、そこでコミットがある度にビルドをしていたのですが、あるときからビルドが終了しない事案が発生。

見てみたらサーバのいくつかのプロセスのCPU利用率が100%に……

直接の原因は「@<code>{===}」と「@<code>{Test}」の間に半角スペースがないことなのですが、根本原因はReVIEWの正規表現に難があったようです。
このくらいなら受け付けてくれるか、少なくとも文法エラーで止まるかして欲しいところですが、がっつり無限ループとあいなりました。

現在のgit版最新版では直っています。
この一つ前の節も見ましょう。


== TeX Liveをインストールしたのにフォントがない！

特にDebian/Ubuntuでありがちなミスという気がします。

@<chap>{how_to_install}で紹介されている方法以外に、Debian/Ubuntuでは@<code>{apt-get}コマンドでTeX Liveをインストールする方法があり、そちらのほうが手頃です。
ただ、パッケージが複数に分かれているため、自分の環境に適したパッケージを選ぶ必要があります。

Debian/Ubuntu系であれば@<code>{texlive-lang-cjk}や@<code>{texlive-fonts-recommended}が入っていることを確認してください。

TechBoosterの関連書籍を筆者のDebian wheezy 7.1の環境下でビルドする際に入っているTeX Live関連のパッケージを念の為添付しますので、ヒントになれば幸いです。

//cmd{
> dpkg -l | grep texlive | awk '{print $2}'
texlive texlive-base texlive-binaries texlive-common texlive-doc-base
texlive-doc-zh texlive-extra-utils texlive-font-utils texlive-fonts-recommended
texlive-fonts-recommended-doc texlive-generic-recommended texlive-lang-cjk
texlive-latex-base texlive-latex-base-doc texlive-latex-extra
texlive-latex-extra-doc texlive-latex-recommended texlive-latex-recommended-doc
texlive-luatex texlive-pictures texlive-pictures-doc texlive-pstricks
texlive-pstricks-doc
//}

TeX Live本家を利用してインストールする場合にフォントがない、という問題を聞くことはほぼありません。

この辺りのチョイスは良し悪しです。
TeX Liveを本家からインストールすると数GBのストレージを食いますし、アップデートはOSディストリビューションとは独立に行うことになります。


== 半角カナが全角カナに！

『Effective Android』の同人誌版から電子書籍版にアップデートする過程で、文章中の半角カナが勝手に全角カナに直ってしまうという事態が発見されました@<fn>{bug_182}。

//footnote[bug_182][@<href>{https://github.com/kmuto/review/issues/182}]

根本的な原因はTeXが標準で半角カナを利用できないことにあったのですが、ある種の拡張に頼ることを前提としてReVIEWのレイヤでうまく処理してもらうようになりました。
TeXはネイティブでUTF-8に対応していないので、これ以外にも種々の問題があるようです。

ReVIEWのレイヤからすると、下位の問題を個別にうまく対応する必要があるわけですから、大変は大変ですね。

== せんせい、打ち消し線を使いたいです

要はHTMLで言う<del></del>のことです。@<fn>{bug_178}

//footnote[bug_178][@<href>{https://github.com/kmuto/review/issues/178}]

ReVIEWでは出力先毎に対応を変更「可能」と言いつつ、全て実装されているわけではありません。
del命令もその一つでした。

そもそもTeXでは標準で打ち消し線を行う実装が存在しないため、外部マクロを用いること、外部マクロでも複数選択肢があること、といった理由から、ReVIEWのPDF出力でも打ち消し線の標準的なサポートはないようです。

TechBoosterでは@<code>{review-ext.rb}に以下のようなコードを記述することで対応しました。

//list[implement_del][TeXにおいて打ち消し線を用いる一例]{
module ReVIEW
  class LATEXBuilder
    def inline_del(str)
      macro('sout', escape(str))
    end
  end
end
//}


== あるはずのファイルがないと言うReVIEW

あるはずのファイルがない時に発生するトラブルがないはずなのにあります@<fn>{bug_214}。

//footnote[bug_214][@<href>{https://github.com/kmuto/review/issues/214}]

章構成を作る@<code>{CHAPS}について@<chap>{first_review_project}で紹介しました。

復習すると「@<code>{review-pdfmaker}や@<code>{review-epubmaker}を使う際にはYAMLファイルを作る必要があり、ついでに@<code>{CHAPS}も作る必要がある」という内容でした。

この際、複数の章を別のファイルで作るため、@<code>{first-chapter.re}の他に@<code>{second-chapter.re}を作成して文章を書き始める例を書いていたときのことです。

//cmd{
> ls
CHAPS first-chapter.re sample.yaml second-chapter.re
> cat second-chapter.re
= ReVIEWコマンド解説
> review-compile --target html second-chapter.re
review-compile: error: no such file: second-chapter.re
//}

ああっと！

調べてみると、@<code>{CHAPS}ファイルがそのディレクトリに収録されているその瞬間から発生するようです。
修正方法は「CHAPSにそのファイル名を加える」です。

//cmd{
> cat CHAPS
first-chapter.re
> echo "second-chapter.re" >> CHAPS
> cat CHAPS
first-chapter.re
second-chapter.re
> review-compile --target html second-chapter.re
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1//EN" "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xmlns:ops="http://www.idpf.org/2007/ops" xml:lang="ja">
<head>
  <meta http-equiv="Content-Type" content="text/html;charset=UTF-8" />
  <meta http-equiv="Content-Style-Type" content="text/css" />
  <meta name="generator" content="ReVIEW" />
  <title>ReVIEWコマンド解説</title>
</head>
<body>
<h1><a id="h2"></a>第2章　ReVIEWコマンド解説</h1>
</body>
</html>
//}

というわけで、一度@<code>{CHAPS}を作ったら、以降ReVIEWファイルの名前は忘れず追加しておきましょう……という話なんですが、それにしても「ファイルがない」はミスリーディングだなぁと。

@<code>{CHAPS}ファイルがある場合、@<code>{review-compile}は同一ディレクトリ内の他のReVIEWを見て章番号や他の章への参照をうまく処理しようとします。
よく見ると、上で出力されたHTMLの中で「第2章」と正しく章番号が設定されていますね。

ただ、執筆時点ではこの部分の実装にバグがあったようで、@<code>{CHAPS}に記述されていないファイルに対しては、何故か、そのファイルがディレクトリにも存在しないかのようなエラーを表示してしまっていました。

自分で直す（Pull Request）余裕もなかったため、最低限レポートをしたところ、翌日には直りました。
今は"No such chapter in your book. Check if the catalog files contain the chapter."と出るはずです。
今度は「catalog filesって何」って思いますが、要は@<code>{CHAPS}, @<code>{PREDEF}, @<code>{POSTDEF}, @<code>{PART}のことです。

== ReVIEWで自分自身は記述できないの？

本書の多くの章でReVIEWの構文紹介があったかと思います。

しかしReVIEWには基本的に自分自身の構文を無視する機能がありません。
紹介しようとすると、それ自体が修飾するべき構文とみなされて読者の読む出力からは消滅してしまうからです。

対策としていくつも案が挙がりましたが、決定打は今のところありません。

 * 全角＠使う
 * //list記法の中では先頭にスペースを入れる
 * 構文解釈を失敗しそうなポイントに\をピンポイントで差し込む
 * ReVIEWの処理系を書き換えてしまう


== みんなで使おう！

より重要なのは、ここで記載されている事項のほとんどは、数日以内に修正されてたりすることなんですよね。

@<chap>{introduction}の課題でも書かれているかと思いますが、「ユーザ数が少ない」ことがダイレクトに本章のトラブルに結びついている、ということが圧倒的に多いと言えます。
そして、開発者の対応自体は大変早いので、結果として致命的な問題は起こらず現状でも執筆出来ています。

というわけで本章を読んだ後でも結論はあまり変わらず「みなさんReVIEW使いましょう」ということになります。

なるよね。