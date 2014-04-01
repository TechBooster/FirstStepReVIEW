= Sublime Text 2でReVIEWを書く

//lead{
ReVIEW記法を理解しても、エディタの補助なしで書くのはなかなか辛いものがあります。
そこで、この章ではSublime Text 2というエディタでReVIEWを書くためのセットアップ方法を紹介します。
//}

Sublime Text 2はシンプルながら拡張性の高いテキストエディタです@<fn>{sublimetext3}。
@<href>{http://www.sublimetext.com/2}からダウンロードすることができます。
無料で試すことができ、継続して利用する場合はライセンスを購入します。
OS X, Windows, Linuxをサポートしていますが、Linuxでは日本語入力がデフォルトでできないという問題があります。

//footnote[sublimetext3][Sublime Text 3というものもあります。@<href>{http://www.sublimetext.com/3}]


Sublime Text 2の大きな特徴の1つのが、プラグインを簡単に開発できるという点です。
シンタックスハイライトを正規表現で指定できますし、入力補完やビルド時に行う処理などをpythonで書くことができます。

そこで、ReVIEW記法に沿ったシンタックスハイライトと入力補完のプラグインを筆者が用意しました。
@<href>{https://github.com/yanzm/ReVIEW}


== Sublime Text 2用ReVIEWプラグインをインストールする

まず、@<tt>{Package Control}というプラグインをインストールします。すでにインストールしている場合はこのステップは必要ありません。

[View] - [Show Console] からコンソールを表示し、コンソールに@<list>{package_control_install}のコマンドを入力します。

//list[package_control_install][Package Control をインストールするためのコマンド]{
import urllib2,os;
pf='Package Control.sublime-package';
url = 'http://sublime.wbond.net/' +pf.replace( ' ','%20' );
ipp = sublime.installed_packages_path();
os.makedirs( ipp ) if not os.path.exists(ipp) else None;
urllib2.install_opener( urllib2.build_opener( urllib2.ProxyHandler( )));
open( os.path.join( ipp, pf), 'wb' ).write( urllib2.urlopen( url ).read());
print( 'Please restart Sublime Text to finish installation');
//}

実行したらSublime Text 2を再起動します。

次に、@<tt>{Command + Shift + p}（Windowsでは@<tt>{Ctrl + Shift + p}）でCommand Paletteを開き、@<code>{Add Repository}を選択します（@<img>{1}）@<fn>{add_repository}。

//footnote[add_repository][Package ControlにReVIEWリポジトリが登録されていればこのステップは不要なのですが、まだ登録依頼を出していないのです。すいませんでしたぁぁぁ。]

//image[1][Package ControlでAdd Repositoryを選択]{

//}

下の方にリポジトリのURLを入力するフォームが表示されるので、@<code>{https://github.com/yanzm/ReVIEW}と入力してEnterを押します（@<img>{2}）。

//image[2][リポジトリにReVIEWプラグインのURLを入力]{

//}	

リポジトリを追加したら、@<tt>{Command + Shift + p}（Windowsでは@<tt>{Ctrl + Shift + p}）で再度Command Paletteを開き、今度は@<code>{Install Package}を選択します（@<img>{3}）。

//image[3][Package ControlでInstall Packageを選択]{

//}

インストールするパッケージを聞かれるので、@<tt>{ReVIEW}を選択するとパッケージがダウンロードされインストールされます（@<img>{4}）。

//image[4][インストールパッケージとしてReVIEWを選択]{

//}

インストールが完了したらSublime Text 2を再起動しておきます。


== ReVIEWプラグインのシンタックスハイライトを使う

ReVIEWプラグインのシンタックスハイライトを利用するには、ファイルの拡張子が .re である必要があります。
また、.re　のファイルを開いたときに [View] - [Syntax] がReVIEWになっていない場合は、[View] - [Syntax] - [Opne all with current extension as...] でReVIEWを選択してください。

//image[5][ReVIEWプラグインによるシンタックスハイライト]{
//}


== ReVIEWプラグインの入力補完を使う

入力補完を表示するには、@<tt>{Ctrl + Space}@<fn>{ctrl_space}を押します。
また、インラインコマンド（@<...>{...}）は「@コマンド名」まで入力して@<tt>{Tab}を押すと、「@<raw>{@}<コマンド名>{}」に変換されます。
ブロックコマンド（//...[]{ ... //}）は「//コマンド名」まで入力してTabを押すと、「//コマンド名[]{...}」に変換されます。

//image[6][Ctrl + Spaceで入力補完を表示した場合]{

//}


//footnote[ctrl_space][Mac OSでは@<tt>{Ctrl + Space}はデフォルトではSpotlightに割り当てられているため、Sublime Text 2を利用する場合は、Sportlightを別のキーに割り当てることをおすすめします。]










