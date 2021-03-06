= 同人誌を作ろう

本章は技術的な内容を同人誌にまとめるという、ごくありふれた創作活動の紹介です。
必ずこうすべきだ、というものではなく、ReVIEWを使った同人誌ってこうやってつくったんだよ、という体験記です。同人誌というジャンルは広く、多様な表現が可能です。
技術誌としての企画、構成、編集、入稿まで制作フローに興味があるとより楽しめると思います。
そしてこれを読んで作ってみたいな、とおもった方はガイドラインとしてご活用ください。

また紙面においての例の多くはTechBoosterのmhidaka（通称、ひつじ）が経験したことがベースです。
具体的にはコミックマーケット84で頒布した『Effective Android』の同人誌版～電子版～商業出版へ展開した経緯や、コミックマーケット85にむけた同人活動、
商業誌への寄稿や単著、共著の執筆活動のノウハウです。

== 企画と募集

=== よろしい、ならば同人誌だ
同人誌を作りたいと思った時がつくり時です。さぁ作ろう、作りましょう、作るんだ！
同人誌を書き出す前に、決めておくとスムーズなことがいくつかあります。

 * 参加イベント
 * 執筆内容と構成案
 
参加イベントの決定は、もっともスケジュールに影響を与えます。なるはやで決めてしまいましょう。
技術書を頒布する@<fn>{hanpu}のに最も適したイベントは、コミックマーケットです。
それ以外にもいくつか探してみましたが、技術書がある程度まとまった規模になるイベントは、ほとんどありませんでした。つまり、一択です。

//footnote[hanpu][同人用語。有償、無償問わず、イベントで同人誌を提供すること]

執筆内容と構成案については言わずもがな、ですね。
この段階ではなかなか予測がつきにくいかもしれませんが、完成時のページ数は、印刷所へ入稿するために重要な情報です。
サイズはB5（JIS）が一般的で、おすすめです。

印刷にかかるお金は大きく異なるため、ページ数と部数は早めに想像しておきましょう。この段階では、きっちり固まっている必要はありません。
経験から技術書は厚い薄い本になりやすいです。ちなみに筆者のサークルがコミックマーケット84で刊行した『Effective Android』は100ページを予定していて、
気が付くと184ページの書籍になりました。まぁそんなもんですよ@<fn>{eng}。

//footnote[eng][もしあなたがエンジニアならわかるはず]

あなたが「どうせつくるなら品質も気にしたいな」と思うなら、最初に決めるべき内容が、もうひとつあります。
それは、本のグランドデザインです。執筆内容にあわせて本のイラストやメインカラーなどテイストを考えておきます。
何かしらの2次創作であればパロディとして、文体を変えたり、構成を整えるとパロディ的な側面を、より強調できます。
また内容に合った表紙は、それだけでうっとりできます。これは間違いありません。
自分で描いてもよいですが、なかなかそうもいかないので、知り合い伝いで探してみてください。

そしてイラストを描くには大変な労力が必要です。
同人誌は商業ベースではないのですが、ご飯だったり、お金だったり、ありがとうの気持ちを伝えるのを忘れずに。

最後に、執筆内容について考える際、最も肝心な構成案についてです。
構成の考え方、出し方は人それぞれだと思いますが、筆者の場合は、その時に旬な技術を取り扱うように心がけてます。
SDKの新バージョンや、Firefox OSなど時々で紹介したいな、と思う技術トピックを中心に構成します。これは読者視点も考慮した考え方です。

企画の原点は、仕事で困っていたことや不便に感じていること、気になっているんだけど調べられていない分野などテーマを決めて調べることがあります。
自分が好きなことを面白く読んでもらうための切り口探し、というのが適切かもしれません。

もっとも、読んで面白いと感じる同人誌は、「ああ、ホントに好きなこと書いたんだろうなぁ」と伝わってきますので、
深く考えず、技術的興味や、好きなジャンルを選んでください。

=== バンドメンバー募集、当方ボーカル。

バンドメンバーがボーカルばかりになっても問題ありません。
たいていの場合、1人で書ききることが多い同人誌ですが、サークルも大小あり、友人や知り合いで集まって書くこともままあります。

筆者の場合、最大35名で書きました。最少は5人です。
多いと書く以外の調整業もそれなりにあるので、はじめは仲のいい友人と一緒にとかいいかも。音楽性の違いによる解散も経験のうちです。

ひとりでやると、それはもうすべてが自由なので、とても気軽なのですが、
それはそれでサークル参加の事務作業であったり、準備なども漏れてしまうことがあり、そわそわする日々になります。
イベント参加に手慣れた人がそばにいれば、これ幸い、相談してください。たいてい知らないルールや手続きのほうが多いです。

さて、一人で書く場合は役割分担も必要ないので本節は読み飛ばしましょう。
複数人で執筆する場合は、役割分担を決めておきます。実際、同人誌を作って頒布しようと思うと意識する項目は結構、多いです（多分、性格にも依存する）。

 * 運営と執筆
 
視点はさまざまですが、基本的には執筆者と編集者、サークル代表などの運営者、という側面があります。
とくに執筆と編集は明確でないと、文章が良い悪いでモメちゃうかもしれません。何度かヒヤッとすることがありました。
誰がどんな権限を持ってるかはどこかにまとめておきましょう。

よくあるのが他人の文章をどこまで編集していいのか、わからない、といった混乱です。
自分の文章ならどんどん直すんですが、やっぱり人の文章だと遠慮しちゃいますよね。

また全体の構成を議論する前に個別の文章について議論することも混乱の元です。
戦術（文章）をどれだけ頑張っても、戦略（構成）の失敗は取り返すことはできません。
適切な粒度での議論を心がけたいものですが、議論になっている最中は、相手の意見に耳を傾け、最大限、尊重してください。

この場合、編集者（運営者）としての役割を誰かが持っているほうがスムーズです。
特定の執筆者が兼任してもうまく機能すると思います。
文章表現、国語は時として「絶対に正しい」みたいな価値観に当てはまりません。
「ちょっと読みにくいんだけど」「僕はそう思わないよ」みたいな状況がほとんどです。
誰の意見を優先したら良いか、という判断基準があるととてもスムーズです。

「Effective Android」のケースでは特定の一人が編集者として立ち回りましたが、それだけでは追いつかなかったです。
相互レビューなどで文章の品質を上げて、結果をGitHubのIssue管理で行っていました。

 * 書く内容を固める

執筆を始める前に、ざっくりと頭の中に書く内容を固めておきましょう。
この時点で筆が進まないようなら、新刊を落とす恐怖におびえることになります。幸いTechBoosterでは新刊を落としたことはありません。

具体的にはセクションのレベル2ぐらい、つまり章と節のタイトルとリード文があれば安心です。
またプログラミングに関する技術書ならサンプルコードが先にあるとさらに余裕です。

技術的検証をやりながらの執筆は、笑えるぐらい遅い、というのが統計上わかっています@<fn>{math}。

//footnote[math][N=1,mhidakaの経験則]

== 執筆 －しんちょくどーですかー？
肝心なのはスケジュール、つまり締切です。
エンジニア諸兄におかれましても、実装が終わりではなく、検証とリリースまで終えてプロジェクト終了というのは周知の事実です。
場合によっては保守、不具合対応という名前でリリース後まで引っ張られますね、おつかれさまです。しかし、安心してください。
同人誌、商業誌の場合は印刷所に入稿したら実装に戻ることはありません！

執筆の締め切りは思ったより早く到来します。印刷所の入稿前日まで原稿を書くことは避けるべきです。ウッ、なぜか胃が痛くなってきました。

ここでは、執筆の心構えと、文章を読みやすくするためのテクニックを紹介します。基本的なお話がメインですが案外と、奥が深いものです。

===  文章を書くのに大切なこと

１つの文章にたくさんの主張を入れると読む人は混乱してしまいます。
ですので、なるべく1つのコンテキスト（章、節、項で主張の大小はあります）では、言いたいことを１つ主張するようにしてください。

読者はあなたの主張を読みたがっています。数ある同人誌のなかから偶然にも興味をもって読んでくれています。
章のはじめには、導入を用意して話の流れを先に説明して、読者と記事のマッチングをはかります。リード文というかたちでもいいですし、
本文の扱いでも問題ありません（本のスタイルとして統一していればよい）。

まとめでは主張の魅力を最大限伝えてください。そのあとの本文を読んだ際の理解度が大幅に向上します。

また文章を書いていると上下を意識して「以上が」「以下のとおりです」など書きたくなりますが
組版の都合で上下が明らかでない場合があります。次のページにいってしまったりするわけですね。
それぞれ「前述のとおり」「次のとおりです」で置き換えるとよいでしょう。

また図、表、サンプルコードについては、

 * 登場前に内容を簡単に説明する一文を書く
 * 登場後に詳しい解説を書く

を念頭に構成してください。読者が読んだときの唐突感や投げっぱなし感がなくなります。

=== 文章を理解してもらうには？

ここでは文法的な、または文章として読みやすくする工夫を紹介します。
ちょっとしたことなのですが、すべてを守ろうとおもうと意外に難しいものです。以下に3点のポイントに絞って、まとめました。

 * 文章は短く、簡素に書く 
 * 初出の用語/概念は説明する 
 * 表現を統一する 

長い文章は、主語、述語の対応が取りにくく（筆者の国語力もありますが）主張があいまいになりがちです。
経験的に技術文章で3行を超える文章（句点「。」で区切られていない長文）は読みづらく感じます。

まれに長くても面白い文章を書く人がいるのですが、
一般的なノウハウというより、国語的な才能の場合があります。技術的な文章であれば、修飾的な表現は割り切って、簡潔に伝えましょう。

執筆者の文体にも依存しますが、意識的に読点「、」を増やすと読みやすくなります。

//emlist[]{
 ひらがながおおめの文章なら読点をなるべくおおめにいれましょう。
 ひらがなが、おおめの文章なら読点をなるべく、おおめにいれましょう。
//}

極端な例ですが、商業出版されている技術書でも、同様の傾向がみられます。
なるべく国語的な難しさを取り払い、わかりやすさを優先しています。

更に、書き進めているうちに用語解説を忘れることがあります。
「文章を書く」という作業は、言い換えるならば、筆者の主張や考えをまとめる、という行為です。

そうして出てきた単語は、いわば筆者の中では、既知のものとなっており、説明不要と思い込んでしまうことがままあります。
読者にとって、初めて出てきた単語は未知の物体Xであり、理解の妨げになることを十分留意して下さい。

最後の「表現の統一」は、ささいなことですが読みやすさに最も影響します。
国語的なことではありますが筆者が主張を文章に落とし込んだあとは、その文章があなたの主張、意見そのものになります。
読みやすさを気にしてしすぎる、ということはありません（もちろん著者の書くモチベーションや勢いも大事なので最後にチェックするといいでしょう）。

同じ概念、事象、構造、ブロック、クラス、メソッドなど、ものごとへの言及は、表現を統一して言い換えないようにしてください。

また商業出版物をよく見ていると、段落も細かくとる書籍が増えているようです。本項「文章を理解してもらうには？」でも段落を細かくとってみました。気付きましたか？
もともとmhidakaの書く文章は、段落が細かいため、読みやすさは感じなかったかもしれません。
いずれにせよ、このあたりは流行がありますから、現在の主流として意識しておけばよいでしょう。

ちなみに、このような書き方の習熟は、才能＋訓練です。商業紙への寄稿や出版の機会に恵まれると自然と身につきますが、なんにせよ自己分析や努力は必要です。
楽しみながらできることが一番ですね。

== 編集 －しめきりそこですよ？

「先生！原稿まだですか？！」という編集のお仕事は、アニメ「サザエさん」の登場人物、伊佐坂先生に対するノリスケのポジションです。

ただ、本当に大事なことは記載された内容を試してみたり、読んでみたりして、わかりやすく表現を書き換えたり、
不足している内容を書き足してもらうようお願いするなど、全体を整える作業こそ、編集者たるノリスケの手腕が問われる瞬間です。

とはいうものの同人誌においては執筆者が兼ねる場合がほとんどです。現に「Effective Android」でも執筆と並行してレビューや修正が行われていました。
ことエンジニアの執筆は趣味や副業的な側面もあるため、自然と時間が限られ、締切との戦いになります。

本節では、技術書として注意したらよいポイントをいくつか列挙していきます。粒度に差はありますが、重要だと思う項目からの紹介です。

=== 文中の文言、装飾について
これまでの同人活動を通じて、執筆者は装飾を使わないほうがよい、と感じてます。
装飾には、いわゆる太字、斜体などフォントの見た目を変えて読みやすくする意図があります。
しかし、利用基準を定めて守るほうがよっぽど難しく、一貫性を保つのが作業量的にしんどい側面もあります。

大事な内容であれば、文章中で注意喚起したほうがよっぽど良いでしょう、という個人的主張のもと、
装飾が必要なときは編集担当者がチェックできる基準でのみ実施すべきです。

=== 文章中の記号は全角が基本（特にカッコ）

こちらも見た目に影響する話です。半角記号は基本的に英字に合わせてフォントが作られています。
文章中で表現として使う場合、記号は全角を利用てください。メソッド名、プログラムのソースコードからの引用はその限りではありません。

=== 文章中の英字で空きは詰める

英単語を文章中に入れる際に次のような書き方があります。

//emlist[]{
2014年1月17日に Effective Android は、インプレスさんから発売されます！
//}

こちらは多分Webの文化か何かだとおもうのですが、紙の書籍では無意味な半角スペースの混入扱いされます。やっぱり見栄えが良くないためですね。

//emlist[]{
2014年1月17日にEffective Androidは、インプレスさんから発売されます！
//}

編集段階で取るのは結構大変です。事前にルールとして共有したいところですね。ちなみに全角スペースであってもNGです。


=== 漢字の開きを統一する
漢字の開き方、は聞きなれない用語かもしれません。漢字をつかうべきか（閉じる）、ひらがなで書くべきか（漢字を開く）、という基準が一定、存在しています。
出版社および編集部ごとに細かい作法は違うため、同人誌を書くにあたって一般的な用法を紹介します（@<table>{kanji}、@<table>{kanji2}）。

//table[kanji][推奨する漢字の開き方]{
推奨の表現	非推奨の表現
-------------------------------------
こと	～する事、した事がある
とき	～した時、～の時、
できる	～出来る
ただし	但し
したがって	従って
のように	～の様に
ない	～が無い
いえる	言える、言う
ひとこと	一言
最も	もっとも
さまざま	様々な表現がある
かかわらず	関わらず
むやみ	無闇
ほうが	方(ホウ)が
ほうが良い	ほうがいい
大掛かり	おおがかり
隠ぺい		隠蔽
さらに	更に
持つ	もつ
//}
//table[kanji2][推奨する漢字の開き方(続)]{
とおり	通り
基づい	基い
見ていく	みていく
使う	つかう
勧め	すすめ、薦め
他	ほか
すでに	既に
付き	つき
分かる	わかる
気をつけ	気を付け
気づく	気付く
すべて	全て
たとえ	例え、例えば
のち	後（ノチ）
たくさん	沢山
中		～のなか、なか
特に	とくに
きれい	綺麗
たいてい	大抵
すぎない	過ぎない、過ぎる
振る舞い	振舞い、ふるまい
相性が良い	相性がよい
//}

経験的に技術書で多い表現は「～出来る」「～様に」「～する事です」などです。
このあたりはどの出版社も、すべて漢字を開いてくる方針で運用していますので、同人誌を作る際も合わせたほうが、よいでしょう。
特に電子書籍や商業出版を次の展開として経験してみると「最初からやっといたほうがよかったでござる！」感がものすごくありました。

=== 文章表現に関するエトセトラ
==== 文体の統一

文体は著者の味となるため、過剰な編集は好みませんが、それでも以下のような文章は編集段階で変更しています

 * ネガティブな表現を利用しない
 * 体言止め、話し言葉は利用しない
 * 「ですます」調と「である」調を混在しない

ネガティブな表現は読者の心証を悪くします。気持ちの問題なのですが、
期待して本を読んでくれている読者にデメリットだけでなくメリットも感じてもらえるように表現をポジティブに改めます。
ネガティブな表現が同人誌そのものに感染して、本をネガティブに捉えられても、もったいないですからね。

体言止め、話し言葉については、技術書であれば平易な表現を心がけて読者の理解に努める方針のもと、著者の文体を壊さない程度に調整しています。

「ですます」調と「である」調の直接の混在はあまりありませんが、著者ごとに癖はあるものです。読んでいてリズムを崩しそうなら修正することがあります。
「Effective Android」では「～だと思います」という文章であれば「です」で編集したり、「～することができます」という表現であれば簡潔に「～できます」と縮めています。
これも気が付いた範囲でしか実施できないですが、編集時には想定読者になりきって読みやすい文章を追及しましょう。

==== サンプルコードの統一

意外に忘れがちなのがサンプルコードのフォーマットチェックです。
紙面においてはサンプルコード（リスト）も本文の一部として扱います。
小さな工夫としては「Effective Android」では紙面を節約するため、タブインデントを2スペースとしています。

=== 表紙、目次、画像のチェック
文章以外での確認項目は次の通りです。

 * 書籍の「はじめに」など執筆者の作業でないところを作る
 * 図表の参照が本文中にあるか確認する
 * 本文、図表が印刷範囲からはみ出ていないか確認する

基本的にすべてのページに目を通し、印刷にあたって問題となる個所をすべて修正してまわります。
最終入稿に近い形で検証するため、フォーマットはPDFです。ちなみに商業出版だと最後は紙に印刷して確認します。
同人誌（技術書）ではデジタル入稿が一般的になっているため、PDFでチェックします。

「本文、図表が印刷範囲からはみ出ていないか確認する」という項目は、折り返しが難しく、自動で対応できない箇所をさします。
技術書でよくあるミスとしては長いメソッド名や大きなテーブルによる紙面からのはみ出しです。
ReVIEWのコンパイル時ログと合わせて検証していきましょう（Too wide...と警告が出ているはずです）。

 * 著者紹介を作る
 * 目次を見て構成や名前を調整する
 * ノンブル（ページ番号）が全頁入ってるか確認

このあたりは調整に時間がかかるものがほとんどです。時間をたっぷり用意しておきたいですね（用意できたためしはありませんが）。
「はじめに」と目次は読者が最初に目に入れる部分です。１ページほどでわかりやすい構成を心掛けるといいでしょう。

== 入稿と頒布

=== 入稿 －よろしくおねがいしまああああす！！
入稿とは印刷所へ最終的な印刷用データを渡すことです。印刷方法はオンデマンドやオフセットなどさまざまな方法があります。
紙の種類も多数あるため詳しい内容については印刷所ごとに、きちんと相談することをおすすめします。ちなみにTechBoosterでは日光企画さんに依頼しています。

同人誌においては基本的に新刊が最も売れます。
在庫は既刊と呼ばれ、新刊ほどの勢いはありません。鉄則は頒布する必要最低限だけ印刷して在庫を持たないことです。
サークルごと部数の指標は違いますが、TechBoosterがコミックマーケット84に参加したときは新刊2冊で450部を用意しました。

オフセット印刷の場合、本文はPDFデータでデジタル入稿します。
表紙のみ指定フォーマットに合わせて用意しますが、基本的にイラストを用意したら、表紙用の装丁をおこない、入稿用データを作成します（@<img>{hyoushi}、@<img>{nyuko}）。

//image[hyoushi][表紙例][scale=0.25]{
//}

入稿には、表紙1（表）と表紙4（裏）に本の厚みも考慮した背を足したサイズが必要です。断ち切りのための遊びがどれぐらい必要か、なども印刷所に確認しておきます。

//image[nyuko][入稿データ]{
//}

=== 頒布 －新刊でました！
もし頒布イベントがコミックマーケットであれば、新刊は印刷所からの直接搬入が主流です。
サークル参加者でも当日に初めて手に取ることになるわけです。ドキドキですね。
新刊が入った段ボールの中には、落丁や乱丁に備えて、いくらか余分に冊数がはいっていることがあります（余部）。

経験上、ポスターやテーブルクロス、頒布価格を書いたポップがあると華やかです。頒布価格は１ページ10円で総ページ数から決めることが多く、
さらにそこから切りのよい数字（１００円単位など）で合わせます。TechBoosterでは厚さのあまり、主力価格帯は1000円になってしまいました…。
ワンコイン（500円）同人誌も需要が高く、部数が伸びる傾向にあります。
またサークル配置は基本的に同じジャンルで集まっています。あなたが欲しいと思う同人誌がそばにあるかもしれません。

頒布の段階では、ReVIEWの特徴であるワンソース、マルチプラットフォームを活かして電子書籍を付録につける、
AmazonやGoogle Playでの販売も視野に入ってきます。ReVIEWを使っている段階で、電子書籍の制作ハードルは非常に低く、再編集の手間が大幅に軽減されます。

=== 創作活動によせて －先生の次回作にご期待ください
本章ではTechBoosterでの経験をベースに同人誌活動を紹介しました。

開発者による技術書作成を推奨したい、と思ったきっかけは、商業出版などでの制作リードタイムの問題です。
近年、インターネットの普及に伴って商業的な技術誌は発行部数を下げ続けています。
これは鮮度の問題で、ニュース性が高い話題はネットメディアで集めるようになってしまったためです。

さらに商業出版される技術書籍についても、制作期間の長さから読者の手に届くときには、価値の低下が始まってしまいます。
書籍の良さのひとつに体系的な技術、情報の蓄積がありますが、技術の陳腐化（というより開発環境やバージョンの更新）が早いわけです。
このような時代の移り変わりに、対抗する手段として開発者による情報発信、創作活動があると考えています。

本章の内容は数ある同人サークルのひとつのケースですが、技術書を作るためにReVIEWを使い倒しています。
得られたノウハウや知見が、読者へのインスピレーションになれば幸いです。
では、次回のコミケでお会いしましょう！
