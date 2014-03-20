
var exec = require('child_process').exec;
var fs = require('fs');

fs.readdir('.', function(err, files){
    if (err) throw err;
    var fileList = [];
    files.filter(function(file){
        return fs.statSync(file).isFile() && /^vvakame-.*\.svg$/.test(file);
    }).forEach(function (file) {
    	var fileName = file.substring(0, file.length - 4);
    	var command = "/Applications/Inkscape.app/Contents/Resources/bin/inkscape -C -T -z --file="+file+" --export-eps="+fileName+".eps --without-gui"
    	console.log(command);
	    exec(command);
    });
});
