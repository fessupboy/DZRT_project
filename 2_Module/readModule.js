var http = require('http');
var dt = require('./module');

http.createServer(function (req, res) {
    res.writeHead(200, {'Content-Type':'type/html'});
    res.write("The date and time are: " + dt.myDateTime());
    res.end();
}).listen(8080);