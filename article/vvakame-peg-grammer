Start "start"
    = _ c:Chapters? _
    ;

Chapters "chapters"
    = c:Chapter cc:Chapters?
    ;

Chapter "chapter"
    = headline:Headline text:Contents?
    ;

// = 章タイトル
Headline "headline"
    = level:"="+ cmd:BracketArg? label:BraceArg? Space* caption:SinglelineContent Newline*
    ;

Contents "contents"
    // eof 検出に &. を使っている
    = &. c:Content cc:Contents? Newline?
    ;

Content "content"
    // TODO InlineElement の後に Ulist / Olist / Dlist が来ると先頭行じゃなくてマッチできてしまうかも
    = c:SinglelineComment / c:BlockElement / c:Ulist / c:Olist / c:Dlist / c:Paragraph
    ;

Paragraph "paragraph"
    = !"=" c:ParagraphSubs _
    ;

ParagraphSubs "paragraph subs"
    = c: ParagraphSub cc:ParagraphSubs?
    ;

ParagraphSub "paragraph sub"
    = c:InlineElement
    / c:ContentText
    ;

ContentText "text of content"
    = text:$( !Newline !Headline !SinglelineComment !BlockElement !Ulist !Olist !Dlist ( !InlineElement [^\r\n] )+ Newline? ContentText? )
    ;

BlockElement "block element"
    = "//" symbol:$(AZ+) args:BracketArg* "{" Newline contents:BlockElementContents? "//}" _
    / "//" symbol:$(AZ+) args:BracketArg* _
    ;

InlineElement "inline element"
    = "@<" symbol:$([^>\r\n]+) ">" "{" contents:InlineElementContents? "}"
    ;

BracketArg "bracket argument"
    = "[" arg:$([^\r\n\]]*) "]"
    ;

BraceArg "brace argument"
    = "{" arg:$([^\r\n\}]*) "}"
    ;

// contents との差は paragraph を切るか切らないか
BlockElementContents "contents of block element"
    = c:BlockElementContent cc:BlockElementContents? _
    ;

BlockElementContent "content of block element"
    // 各要素は Newline で終わらなければならない
    = c:SinglelineComment / c:BlockElement / c:Ulist / c:Olist / c:Dlist / c:BlockElementParagraph
    ;

BlockElementParagraph "paragraph in block"
    = c:BlockElementParagraphSubs _
    ;

BlockElementParagraphSubs "paragraph subs in block"
    = c: BlockElementParagraphSub cc:BlockElementParagraphSubs?
    ;

BlockElementParagraphSub "paragraph sub in block"
    = c:InlineElement
    / c:BlockElementContentText
    ;

BlockElementContentText "text of content in block"
    = text:$( ( &. !"//}" !SinglelineComment !BlockElement !Ulist !Olist !Dlist ( !InlineElement [^\r\n] )+ Newline? )+ )
    ;

InlineElementContents "contents of inline element"
    = !"}" c:InlineElementContent cc:InlineElementContents?
    ;

InlineElementContent "content of inline element"
    = c:InlineElement / c:InlineElementContentText
    ;

InlineElementContentText "text of inline element"
    = text:$( ( !InlineElement [^\r\n}] )+ )
    ;

SinglelineContent "inline content"
    = c:ContentInlines (Newline / EOF)
    ;

ContentInlines "children of inline content"
    = c:ContentInline cc:ContentInlines?
    ;

ContentInline "child of inline content"
    = c:InlineElement / c:ContentInlineText
    ;

ContentInlineText "text of child of inline content"
    = text:$( ( !InlineElement [^\r\n] )+ )
    ;

// * 箇条書き
Ulist "ulist"
    // 行頭から… の指定がない
    = c:(UlistElement / SinglelineComment) cc:Ulist?
    ;

UlistElement "ulist element"
    = " "+ level:"*"+ Space* text:SinglelineContent
    ;

// 1. 番号付き箇条書き
Olist "olist"
    // 行頭から… の指定がない
    = c:(OlistElement / SinglelineComment) cc:Olist?
    ;

OlistElement "olist element"
    = " "+ n:Digits "." Space* text:SinglelineContent
    ;

// : 用語リスト
Dlist "dlist"
    // 行頭から… の指定がない
    = c:(DlistElement / SinglelineComment) cc:Dlist?
    ;

DlistElement "dlist element"
    = " "* ":" " " Space* text:SinglelineContent content:DlistElementContent _
    ;

DlistElementContent "content of dlist element"
    = [ \t]+ c:SinglelineContent
    ;

SinglelineComment "signle line comment"
    = text:$("#@" $([^\r\n]*) Newline?) _
    ;

Digits "digits"
    = $(Digit+)
    ;

Digit "digit"
    = [0-9]
    ;

AZ "lower alphabet"
    = [a-z]
    ;

Newline "newline"
    = "\r\n"
    / "\n"
    ;

_ "spacer"
    = $([ \t\r\n]*)
    ;

Space "space"
    = [ 　\t]
    ;

EOF "end of file"
    = !.
    ;
