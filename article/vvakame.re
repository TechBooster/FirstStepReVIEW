= ReVIEW.js で学ぶ ReVIEW記法のお約束

== ReVIEW.jsってなに？

筆者は、Rubyによる実装であるところの本家ReVIEWを参考に、JavaScript実装@<fn>{actually-typescript}であるReVIEW.jsを作成しています。
現在のバージョンは 0.1.0 です。
ReVIEW.jsはNode.jsとモダンブラウザ上で動作させることを念頭において開発されています。
とりあえず試してみたい場合は @<href>{http://vvakame.github.io/review.js/} で試すことができます@<fn>{poor-design}。

ReVIEW.jsは以下の理由により開発がスタートしました。

 1. Ruby版ReVIEWは原稿のパーサとコンパイラが分割されていないため、構文的に整合性が取りにくい。
 2. 出力用のビルダ毎にサポートされている構文に差があり、何も考えずに書くとエラーになる場合がある@<fn>{pull-request-is-mandetory}。
 3. Ruby版ReVIEWを利用するにはコマンドラインを使わねばならないため、導入の敷居が高いため、Webブラウザ上で動かしたい。
 4. 利用可能な構文を処理系から得られず、書籍のために独自構文を追加した時にエディタ側のサポートが得にくい。

現実的な応用として、技術的なブログ記事の執筆にReVIEWが使いにくいという問題があります。
これは、ブログ用アプリケーションがReVIEW記法をサポートしていないためです。
技術ブログ→書籍化 という流れも多い昨今ですので、ブログ上での記述にReVIEWがサポートできるとなるとメリットも大きいでしょう@<fn>{web-powered-by-review}。
そのための策として、ReVIEW.jsが有効に機能するかもしれません。

もっともらしいことを書きましたが、本当は ブラウザ上でReVIEWの原稿の編集が行える @sys1yagi 製ツール PreVIEW@<fn>{preview-editor} が裏側で必死にRuby版動かしているのを見て、ブラウザ上で全部やっちまいなよ！と思ったのが開発スタートの原因です。
アトウッドの法則「全てのJavaScriptで記述可能なアプリケーションは、ゆくゆくはJavaScriptで書き直される」の通りですね :)

//footnote[actually-typescript][まぁ、JavaScript版といいつつ実装はTypeScriptなんですけどね。TypeScript可愛いよぺろぺろ。]
//footnote[poor-design][筆者はAPIを美しくすることは得意ですがUIを美しくするのはめっちゃ不得意なので誰か助けてくれてもいいのよ！？]
//footnote[pull-request-is-mandetory][無いなら自分で作ればいいじゃない！ @<href>{https://github.com/kmuto/review/pull/179}]
//footnote[web-powered-by-review][Qiitaさん見てますかー？ﾁﾗｯﾁﾗｯ]
//footnote[preview-editor][@<href>{https://github.com/sys1yagi/PreVIEW}]

=== よりリッチな入力補完のための工夫

ReVIEW.jsでは、エディタ上での快適な編集をサポートするために利用可能な構文を処理系から取得することができます。
@<href>{http://vvakame.github.io/review.js/} で表示される構文は、全て処理系から得たもので、引数の数などは実際に受理可能なもののみが出力されています(@<list>{syntax-sample})。

//list[syntax-sample][処理系から得られる出力のサンプル]{
{
  "rev": "1",
  "SyntaxType": {
    "0": "Block",
    "1": "Inline",
    "2": "Other",
    "Block": 0,
    "Inline": 1,
    "Other": 2
  },
  "acceptableSyntaxes": [
    ...,
    {
      "type": 0,
      "symbolName": "image",
      "argsLength": [
        2,
        3
      ],
      "description": "図表を示します。\n//image[sample][サンプル][scale=0.3]{\nメモ\n//}\nという形式で書きます。\n章のファイル名がtest.reの場合、images/test-sample.jpegが参照されます。\n画像のサイズを調整したい場合、scaleで倍率が指定できます。\n中に書かれているメモは無視されます。"
    },
    ...
  ]
}
//}
//noindent
=== ビルダ毎のサポートしている構文の統一

ReVIEW.jsでは、字句解析&構文解析、意味解析、コード生成が切り分けられています。
また、入力補完候補を得るために全ての構文の収集が実行時に可能なように設計されているため、利用するビルダ全てでサポートされている構文に不足がないかを事前に検査することができます。
そのため、実装が足りないビルダを使おうとするとエラーにすることができるため、ビルダ作成時の効率的なテストとして役立てることができます。

=== ReVIEWパーサの作成

ReVIEW記法に対してパーサを作成しました。
peg.jsという、PEG記法を用いたパーサジェネレータを利用しています。
@<href>{https://github.com/vvakame/review.js/blob/master/src/main/peg/grammer.pegjs} にて、内容が参照できます。
PEG記法を用いたパーサジェネレータ同士でも書き方に互換性がないので何も変えずにそのまま流用、というのは難しいのですが、Rubyプログラムから頑張って移植するよりはパーサ部分の汎用性が高くなります。

本章のこの後の節では、このReVIEWパーサを題材にして正しいReVIEW原稿の書き方を学んでいきましょう@<fn>{exemption-from-responsibility}。

//footnote[exemption-from-responsibility][免責事項：頑張ってPEG記法に起こして、割りと頑張ってRuby版が受理できる原稿を同じく受理できるようにしたつもりだけど、頑張りきれていなかったらごめんね！バグ報告もよろしくね！]

=== まだまだRuby版には追いつかない

もちろん、長い間幾多のユーザの利用に耐え、開発が継続されてきたRuby版ReVIEWには追いつけていません。
まずは、このReVIEW本の原稿の処理全てをReVIEW.jsで…といいたいところですが、実装されていない機能がそれなりにあるため、それもままなりません。
悲しいですね。

実装が追いついていない機能は以下の通りです。

 * 本としての処理
 ** PDFやepubの生成
 * TextとHTML以外のビルダの作成。特に重要なのがLaTeXのビルダですが全く手付かずです。
 ** LaTeXビルダ
 ** idgxmlビルダ
 ** markdownビルダ
 * サポートされていない記法の存在
 ** LaTeXビルダ用の記法なので実装されていない
 *** texequation ブロック記法
 *** m インライン記法
 ** Ruby版の仕様がよく理解できないので実装されていない
 *** chap インライン記法
 *** title インライン記法
 *** chapref インライン記法
 *** bibpaper ブロック記法
 *** bib インライン記法
 ** 実装方法を考えている最中なので実装されていない
 *** raw ブロック記法
 *** raw インライン記法
 *** graph ブロック記法
 *** table ブロック記法
 *** tsize ブロック記法
 *** table インライン記法
 *** コラム用の記法
 * プリプロセッサ
 ** #@mapfile など
 * その他細々としたもの
 ** 気がついていないものがたくさんある気がする…！

//noindent
table記法マジラスボス…。というか仕様がでかいです。
入れ子が可能な設計にすると単純にタブ文字で分割してやればいいじゃん、というわけにもいかず。
正直table記法さんだけ特殊すぎるので何か良い記法を編み出すとかしたほうがよいような気が…。

== ReVIEW記法を調べよう！

長い前置きでした。
ReVIEW.jsで使っているPEG記法をシンタックスダイアグラムに変換し、それを見ていきます。

@<href>{http://bottlecaps.de/convert/} でgrammer.pegjs（ReVIEW.jsの構文ファイル）を投げ込み、EBNFに変換し、さらに @<href>{http://bottlecaps.de/rr/ui} に投げてシンタックスダイアグラムを得ます。

さて、その結果を見て行きましょう。

=== 肩慣らしに基礎となる簡単なブロックから

==== Digit

[0-9] というのは、0, 1, 2, 3, 4, 5, 6, 7, 8, 9 のいずれかにマッチします。
つまり、数字1文字であればなんでもいい…ということになります。
正規表現の書き方と同じですので、わかりやすいですね。

//image[Digit][Digit. 0, 1, ..., 9 のいずれか数字1文字]{
Digit "digit"
    = [0-9]
    ;
//}
//noindent
==== Digits

Digitから出た線が、またしてもDigitに戻ってくるルートがあります。
つまり、Digit（数字1文字）が1回以上連続しているもの全てにマッチします。

//image[Digits][Digits. Digitが1回以上連続していること]{
Digits "digits"
    = $(Digit+)
    ;
//}
//noindent
==== AZ

Digitは数字1文字でしたが、今度はアルファベットの小文字1文字にマッチします。
AZという名前だと大文字1文字っぽい感じがしますね…。
なぜ、こんな定義が必要かというと、Ruby版ReVIEWの @<nanika> {} のnanikaの部分はアルファベット小文字のみで構成されていないといけない制約があり、それを真似するためです。

//image[AZ][AZ. a, b, ... , z のいずれかアルファベット小文字1文字]{
AZ "lower alphabet"
    = [a-z]
    ;
//}
//noindent
==== Newline

これはWindowsで一般的な CRLF とUnix系で多く見られる LF を1つの改行とみなしてマッチします。
PEG記法では、上に書いてあるものが優先してマッチされます。

//image[Newline][Newline. 改行を表す]{
Newline "newline"
    = "\r\n"
    / "\n"
    ;
//}
//noindent
==== Space

空白1文字と認識されるものを定義しています。
半角スペース、全角スペース、タブが含まれます。

//image[Space][Space. 半角スペースとタブ、改行を含む]{
Space "space"
    = [ 　\t]
    ;
//}
//noindent
==== _ （スペーサ）

ReVIEW上、読み捨てできる文字の塊と認識されるものにマッチします。
迂回路があることからわかる通り、0文字にもマッチします。
つまり、このパターンは失敗しません。

//image[_][_. 読み飛ばすべき空白][scale=0.75]{
_ "spacer"
    = $([ \t\r\n]*)
    ;
//}
//noindent
==== @<kw>{EOF,End Of File}

これはファイルの最後であることを指します。
つまり、もうこの後に何も続いてはならない…！というパターンにマッチします。

//image[EOF][EOF. ファイルの終端]{
EOF "end of file"
    = !.
    ;
//}
//noindent
=== ReVIEW記法の構造に迫る

いよいよReVIEW記法の詳細に迫っていきましょう。

==== Start

ReVIEW文書のスタート地点です。
全てのReVIEW文章は複数のチャプター（章）を含むことができます。
含むことができる、というだけで、実際は複数の章を1つの .re ファイルに押し込むのは良いやり方ではありません。
処理系を甘やかすためにも、1ファイル1章になるようにしましょう。

最初と最後に _（無視するべき空白）があります。これは無視してしまうので出力には関係ありません。

//image[Start][Start. ReVIEW文書は複数のチャプターから成り立つ]{
Start "start"
    = _ c:Chapters? _
    ;
//}
//noindent
====  Chapters, Chapter

Chapterは、日本語訳すると "章" にあたりますが、ReVIEW.js内部では 章、節、項、段、小段 の全てを指します。
これは、Ruby版のReVIEWが章（見出し深さ1）の下に項（見出し深さ3）を許す設計になっているためです。
これも、可能なだけで実際に深さ2を飛ばしてしまうのは悪い作法なので、処理系レベルで制限してしまったほうが良いとは思うのですけどね。

1つのChapterはHeadline（見出し本体）とContents（コンテンツ）からなります。

//image[Chapters][Chapters. 複数のチャプターから成る]{
Chapters "chapters"
    = c:Chapter cc:Chapters?
    ;
//}
//noindent
//image[Chapter][Chapter ヘッドライン（見出し）とコンテンツ（本文）から成る]{
Chapter "chapter"
    = headline:Headline text:Contents?
    ;
//}
//noindent
==== Headline

ようやっと、生の文字列の指定がでてきました。
Headlineは、日本語訳すると "表題" になります。
文章を書き始める時に @<tt>{= 表題} と書くと、これがそのままHeadlineになります。
途中で BracketArg, BraceArg （後述）が出てきます。これらはそれぞれ、[] と {} に対応しています。
[] は、コラムを書く時に使います。
@<tt>{=[column] コラムの表題} と書くと、コラムになります。
コラムを終える時は次のChapterを書き始めるか、@<tt>{=[/column]}で閉じる必要があります。

[] の中に来るものは、必ず column に限定されますが、ReVIEW.jsではそのような制約を設けていません（実装してる時は知らなかったんだ！）。
さらに、@<tt>{=[/column]}でコラムを終えることもできません（実装してる時は知らなかったんだよ！！）。

@<tt>{= 表題} の "表題" にあたる部分は SingleLineContent（後述）として定義されています。
このため、ReVIEW.jsでは表題中でもインライン記法が利用可能になっています。LaTeXなどの環境をターゲットにした時にポータブルにならなさそうではあります…。

//image[Headline][Headline. 見出しを表す]{
Headline "headline"
    = level:"="+ cmd:BracketArg? label:BraceArg? Space* caption:SinglelineContent Newline*
    ;
//}
//noindent
==== Contents, Content

Chapterの本文の部分にあたります。
それぞれ、SinglelineComment（1行コメント）, BlockElemt（ブロック記法）, Ulist（箇条書き）, Olist（数字付き箇条書き）, Dlist（用語の定義）, Paragraph（段落）があり、Chapterの本文はこれらの繰り返しからなります。

//image[Contents][Contents. Contentの繰り返しから成る]{
Contents "contents"
    // eof 検出に &. を使っている
    = &. c:Content cc:Contents? Newline?
    ;
//}
//noindent
//image[Content][Content. いろいろなものが本文に成りうる][scale=0.75]{
Content "content"
    // TODO InlineElement の後に Ulist / Olist / Dlist が来ると先頭行じゃなくてマッチできてしまうかも
    = c:SinglelineComment / c:BlockElement / c:Ulist / c:Olist / c:Dlist / c:Paragraph
    ;
//}
//noindent
==== Paragraph

ParagraphはReVIEW.jsが使っているパーサジェネレータのPEG.jsの処理の仕様上、ParagraphSubs, ParagraphSub を持ちます。
ざっくり意図を説明すると、Paragraph は InlineElement（インライン記法）, ContentText（地の文, プレーンテキスト） の繰り返しから構成されます。

Paragraphは、行頭に = が来る（新たなChapterの始まりを意味する）ことのない場合のみにマッチします。
ダイアグラム上では省略されていますが、実際のPEG記法では以下のようになっています。
!"=" による、否定先読みが入っていることがわかります。

//emlist{
Paragraph "paragraph"
    = !"=" c:ParagraphSubs _
    ;
//}
//noindent
//image[Paragraph][Paragraph. 行頭が = ではないParagraphSubsから成る]{
Paragraph "paragraph"
    = !"=" c:ParagraphSubs _
    ;
//}
//noindent
//image[ParagraphSubs][ParagraphSubs.]{
ParagraphSubs "paragraph subs"
    = c: ParagraphSub cc:ParagraphSubs?
    ;
//}
//noindent
//image[ParagraphSub][ParagraphSub. インライン記法とプレーンテキストから成る]{
ParagraphSub "paragraph sub"
    = c:InlineElement
    / c:ContentText
    ;
//}
//noindent
==== ContentText

これは地の文、かつ、プレーンテキスト（インライン記法ではない）です。

ダイアグラム上は現れていませんが、大量の否定先読みが入っています。

先頭が

 * 改行ではない
 * Headlineではない（新しいChapterの始まりではない）
 * SinglelineCommentではない
 * BlockElementではない（BlockElementはParagraphではない）
 * Ulistではない（UlistはParagraphではない）
 * Olistではない（OlistはParagraphではない）
 * Dlistではない（DlistはParagraphではない）

かつ

 * InlineElementではない（InlineElementはContentTextではない）
 * 改行ではない

を満たす文字列にマッチします。
改行またはEOFを見つけたらそこで処理を打ち切り、1つ改行を食べられたら食べます。
その後に続くものがさらにContentTextの場合は、ContentTextの続きとして処理します。

はぁっ！複雑！わかりにくく、辛く長いルールですね。
一回日本語でまとめてみましょう。

ContentTextは、改行が2つ連続しない限りマッチする（2つ連続でマッチしたらParagraphの切れ目）。
"連続でマッチする文字列"と呼ばれるものは、ブロック記法や新しいChapterの始まりなど、Paragraphの切れ目に当たるものが来ないようにする。
また、Paragraphの中にはContentTextとInlineElementが混在する場合があるため、InlineElementを見つけたらその直前までを1つのContentTextとする。

自然言語の記述力の高さが光ります。これだけの指示でパソコンが全部理解してくれると、パソコンから僕への愛を感じるのですが、残念ながら今まで僕はパソコンさんからの愛を受け取ったことがありません。

#@# review by KG リストからはみ出してるので適宜改行を入れてください。
#@# ↑チェックしたお！
//emlist{
ContentText "text of content"
    = text:$( !Newline !Headline !SinglelineComment !BlockElement \ # 本当は一行
              !Ulist !Olist !Dlist ( !InlineElement [^\r\n] )+ Newline? ContentText? )
    ;
//}
//noindent
//image[ContentText][ContentText. プレーンテキスト]{
ContentText "text of content"
    = text:$( !Newline !Headline !SinglelineComment !BlockElement !Ulist !Olist !Dlist ( !InlineElement [^\r\n] )+ Newline? ContentText? )
    ;
//}
//noindent
==== BlockElement

これはブロック記法を表します。例えば、以下のようなものです。

//emlist{
 //list[sample][サンプルだよー]{
 console.log("Hello world!");
 //}
//}

ブロック記法は行頭が // で始まり@<fn>{how-beggining-of-line-detected}、そこにシンボルが続きます。
シンボルはAZ（aからzまでのアルファベット小文字）のみ許可されます。
わかりやすさのためには、@<tt>{//リスト[サンプル][サンプルだよー]}というように日本語も許したほうが非技術者の人にもわかりやすいと思うのですけどね。
ここは、Ruby版実装に倣っています。

続く BracketArg は [] の事です。0個以上の引数を書くことが可能です。

最後に { と //} を使って対象範囲をくくります。
ブロック記法は範囲の指定ナシにすることもできるため、末尾の改行を食べる _ のみが配置されている分岐もあることがわかります。

対象範囲は BlockElementContents として表されます（後述）。

//image[BlockElement][BlockElement. ブロック記法を表す]{
BlockElement "block element"
    = "//" symbol:$(AZ+) args:BracketArg* "{" Newline contents:BlockElementContents? "//}" _
    / "//" symbol:$(AZ+) args:BracketArg* _
    ;
//}
//noindent

//footnote[how-beggining-of-line-detected][行頭で始まり、とは書きましたが、それを強制するルールはないので、BlockElementのマッチの判定が始まった時は、必ず改行文字が食われた直後である、というようにルールを作ることで対応しています。辛い。]

==== InlineElement

これはインライン記法を表します。例えば、以下のようなものです。

//emlist{
まずは@<list> {sample}を参照してください。
//}

インライン記法は @< で始まり、そこにシンボルが続きます。
さらに畳み掛けるように >{ ！内容に InlineElementContents（後述）！おしまいに } と続きます。

さて、ブロック記法と違って、こちらのシンボルはなぜ改行と>以外の全ての文字を許すようになっているんでしょうか。
あとでRuby版の挙動見て修正しないと…。
まぁ、文法規則修正するだけで処理系は全く手を付けずに済むので楽なもんですけどね！（強気）

//image[InlineElement][InlineElement. インライン記法を表す]{
InlineElement "inline element"
    = "@<" symbol:$([^>\r\n]+) ">" "{" contents:InlineElementContents? "}"
    ;
//}
//noindent
==== BracketArg

すでに何度か登場していますね。

改行または]以外の文字を引数として取ります。
引数にあたる部分を [ と ] で囲みます。

//image[BracketArg][BracketArg. [\]を使った引数の指定を表す]{
BracketArg "bracket argument"
    = "[" arg:$([^\n\]]*) "]"
    ;
//}
//noindent
==== BraceArg

すでに何度か登場していますね。

改行または}以外の文字を引数として取ります。
引数にあたる部分を { と } で囲みます。

//image[BraceArg][BraceArg. {}を使った引数の指定を表す]{
BraceArg "brace argument"
    = "{" arg:$([^\n\}]*) "}"
    ;
//}
//noindent
==== BlockElement のコンテンツ部分

ブロック記法の本文の部分です。
ブロック記法内ではインライン記法が有効であることと、モノによってはParagraphなどの文脈をサポートするものがあります。
例えば、lead ブロック記法ではまるでブロック記法の中ではないかのように、段落やら箇条書きやらを認識してくるので、頑張ってこれも対応する必要があります。
そのための BlockElementContents, BlockElementContent, BlockElementParagraph, BlockElementParagraphSub, BlockElementContentText です。

既出の内容とほぼ同一なので、全体的に説明をカットしますが、BlockElementContentText だけ見どころがあるので取り上げます。
ContentText と BlockElementContentText を比較してみましょう。

#@# review by KG リストからはみ出してるので適宜改行を入れてください。
#@# ↑チェックしたお！
//emlist{
BlockElementContentText "text of content in block"
    = text:$( ( &. !"//}" !SinglelineComment !BlockElement \ # 本当は一行
              !Ulist !Olist !Dlist ( !InlineElement [^\r\n] )+ Newline? )+ )
    ;
//}
//noindent
#@# review by KG リストからはみ出してるので適宜改行を入れてください。
#@# ↑チェックしたお！
//emlist{
ContentText "text of content"
    = text:$( !Newline !Headline !SinglelineComment !BlockElement \ # 本当は一行
              !Ulist !Olist !Dlist ( !InlineElement [^\r\n] )+ Newline? ContentText? )
    ;
//}

ContentTextとの一番大きな差異は、先頭の、何を見つけたらマッチングを打ち切るか、という指定です。
BlockElementContentText はブロック記法の終端、つまり //} で始まらない という指定です。
ContentText はParagraph、ひいてはChapterの始端である Headline で始まらない という指定です。
ここの差異のおかげで共通化出来ない部分になっちゃってるんですよねぇ。処理上は一緒くたに扱ってるのでまぁPEG記法上の問題なんですが。

//image[BlockElementContents][BlockElementContents. Contents 相当]{
// contents との差は paragraph を切るか切らないか
BlockElementContents "contents of block element"
    = c:BlockElementContent cc:BlockElementContents? _
    ;
//}
//noindent
//image[BlockElementContent][BlockElementContent. Content 相当][scale=0.7]{
BlockElementContent "content of block element"
    // 各要素は Newline で終わらなければならない
    = c:SinglelineComment / c:BlockElement / c:Ulist / c:Olist / c:Dlist / c:BlockElementParagraph
    ;
//}
//noindent
//image[BlockElementParagraph][BlockElementParagraph. Paragraph 相当 先頭での = の否定先読みを行わない]{
BlockElementParagraph "paragraph in block"
    = c:BlockElementParagraphSubs _
    ;
//}
//noindent
//image[BlockElementParagraphSubs][BlockElementParagraphSubs. ParagraphSubs 相当]{
BlockElementParagraphSubs "paragraph subs in block"
    = c: BlockElementParagraphSub cc:BlockElementParagraphSubs?
    ;
//}
//noindent
//image[BlockElementParagraphSub][BlockElementParagraphSub. ParagraphSub 相当]{
BlockElementParagraphSub "paragraph sub in block"
    = c:InlineElement
    / c:BlockElementContentText
    ;
//}
//noindent
//image[BlockElementContentText][BlockElementContentText. ContentText 相当だが否定先読みが少し増えている]{
BlockElementContentText "text of content in block"
    = text:$( ( &. !"//}" !SinglelineComment !BlockElement !InlineElement !Ulist !Olist !Dlist ( !InlineElement [^\r\n] )+ Newline? )+ )
    ;
//}
//noindent
==== InlineElement のコンテンツ部分

インライン記法の中はできることが限られているため、定義も簡素になっています。

//image[InlineElementContents][InlineElementContents. Contents に相当]{
InlineElementContents "contents of inline element"
    = !"}" c:InlineElementContent cc:InlineElementContents?
    ;
//}
//noindent
//image[InlineElementContent][InlineElementContent. Content に相当]{
InlineElementContent "content of inline element"
    = c:InlineElement / c:InlineElementContentText
    ;
//}
//noindent
//image[InlineElementContentText][InlineElementContentText. ContentTextに相当 簡素！]{
InlineElementContentText "text of inline element"
    = text:$( ( !InlineElement [^\r\n}] )+ )
    ;
//}
//noindent
==== SinglelineContent

そろそろ解説も終盤戦に近づいてきたと信じたいところで SinglelineContent です。
その下に ContentInlines, ContentInline, ContentInlineText があります。
これもContents, Content, ContentText と同様の構造です。
Headline のように1行で書かれる必要のある文を表します。
後述の UlistElement, OlistElement, DlistElement でも利用されます。

//image[SinglelineContent][SinglelineContent. 1行に収まるコンテンツ]{
SinglelineContent "inline content"
    = c:ContentInlines (Newline / EOF)
    ;
//}
//noindent
//image[ContentInlines][ContentInlines. Contents に相当]{
ContentInlines "children of inline content"
    = c:ContentInline cc:ContentInlines?
    ;
//}
//noindent
//image[ContentInline][ContentInline. Content に相当]{
ContentInline "child of inline content"
    = c:InlineElement / c:ContentInlineText
    ;
//}
//noindent
//image[ContentInlineText][ContentInlineText. ContentText に相当]{
ContentInlineText "text of child of inline content"
    = text:$( ( !InlineElement [^\r\n] )+ )
    ;
//}
//noindent
==== Ulist

箇条書きを表します。
見て分かる通り、行頭には必ず半角スペース1つ以上が必要です。
また、その後の * が複数回連続させることで深さを変えることができます。
筆者はMarkdownのように、* 文字の前にスペースを入れて深さを調節する方法より、ReVIEWの方法のほうが簡単に深さの変更ができるため便利なので好きです。

//image[Ulist][Ulist. 箇条書き]{
// * 箇条書き
Ulist "ulist"
    // 行頭から… の指定がない
    = c:(UlistElement / SinglelineComment) cc:Ulist?
    ;
//}
//noindent
//image[UlistElement][UlistElement. 1行ごとの記法]{
UlistElement "ulist element"
    = " "+ level:"*"+ Space* text:SinglelineContent
    ;
//}
//noindent
==== Olist

数字付きの箇条書きを表します。
これも Ulist と同様に、行頭に半角スペース1つ以上が必要です。
また、1. のような数字はいくつでも問題ない構造になっていて、Ruby版ReVIEWの仕様では自動で採番されなおすことになっていますが、一部ビルダの出力先の都合上、人力で正しい番号どおりに並べたほうがよいそうです。

//image[Olist][Olist. 数字付き箇条書き]{
// 1. 番号付き箇条書き
Olist "olist"
    // 行頭から… の指定がない
    = c:(OlistElement / SinglelineComment) cc:Olist?
    ;
//}
//noindent
//image[OlistElement][OlistElement. 1行ごとの記法]{
OlistElement "olist element"
    = " "+ n:Digits "." Space* text:SinglelineContent
    ;
//}
//noindent
==== Dlist

用語の定義と解説を表します。
これはめずらしく行頭に半角スペースがなくても大丈夫です
しかし、解説の行はかならず行頭に半角スペースまたはタブがなければなりません。

//image[Dlist][Dlist. 用語の定義と解説を表す]{
// : 用語リスト
Dlist "dlist"
    // 行頭から… の指定がない
    = c:(DlistElement / SinglelineComment) cc:Dlist?
    ;
//}
//noindent
//image[DlistElement][DlistElement. 定義の行]{
DlistElement "dlist element"
    = " "* ":" " " Space* text:SinglelineContent content:DlistElementContent _
    ;
//}
//noindent
//image[DlistElementContent][DlistElementContent. 解説の行]{
DlistElementContent "content of dlist element"
    = [ \t]+ c:SinglelineContent
    ;
//}
//noindent
==== SinglelineComment

これは1行コメントで、処理上は単に無視されます。

//image[SinglelineComment][SinglelineComment. 1行コメント]{
SinglelineComment "signle line comment"
    = text:$("#@" $([^\r\n]*) Newline?) _
    ;
//}
//noindent
=== まとめ

いかがだったでしょうか？
これがReVIEWの書き方の全てです。
字句解析&構文解析上は上記に当てはまるように書けば良いでしょう。
#@# 「構文木が変える処理」とは？
#@# ↑修正なう
一部、意味解析のフェーズで撥ねられたり、構文木を組み替える処理を行う場合もありますが、概ねこの通り解釈されます。

複雑な構文はほとんど存在せず、タイトルを書いて、ブロック記法、インライン記法、箇条書きと用語の定義の記法さえ覚えれば、ReVIEWの正しい構文の書き方は覚えたと言って良いでしょう。
問題となるのはブロック記法、インライン記法の各種シンボルの使い方を覚えるだけです！！

とか書くと、HTMLなんか < と > で囲むだけでハイパーシンプルじゃないかふざけんな！という声も聞こえてきそうですが。
それでも、ReVIEW記法を覚えるのは簡単ですよね！！

各種シンボルの解説については@<chapref>{markup}を参照してください。

では、快適なReVIEWライフを！

最後に、ReVIEW.jsはバグ報告、pull request、開発に専念するための出資などを随時受け付けております。
よろしくお願いします☆
