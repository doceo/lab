const char webpage[] PROGMEM =

"HTTP/1.1 200 OK\r\n"
// ***** WEBPAGE STARTS HERE *****
"Content-Type:text/html\r\n"
"Connection:keep-alive\r\n"
//"Connection:close\r\n"
"\r\n"
"<html>\r\n"
"<title>RoboWiFi</title>\r\n"
"<head>\r\n"
// Head starts here
//"<meta http-equiv='Content-Type' content='text/html;charset=UTF-8'>\r\n"
//"<meta charset='utf-8'>\r\n"
"<meta name='viewport' content='width=device-width,user-scalable=no,minimum-scale=1.0,maximum-scale=1.0'>\r\n"
"<style>\r\n"
// CSS starts here
// #2B2A30
//"#container{width:100%;height:100%;overflow:hidden;padding:0;margin:0;-webkit-user-select:none;-moz-user-select-none;}\r\n"
//"body{background-color:black;text-align:center;font-family:sans-serif;font-size:16px;color:white;}\r\n"
"body{background-color:#202020;}\r\n" //color:grey;
//"input[type=range]{-webkit-appearance:none; width:90%; height:30px; background-color:#CAD0E6;}\r\n"
//"::-webkit-slider-thumb{-webkit-appearance:none; background-color:darkorange;"
//"opacity:1.0; width:30px; height:60px;}\r\n"
//"button{width:26%; padding:13% 0; border-radius:50%; background-color:#CAD0E6;}\r\n"
"</style>\r\n"
// CSS ends here
"</head>\r\n"
// Head ends here
"<body>\r\n"
// Body starts here
//"<h1>ISISS Matese</h1>\r\n"
//"<h2>Laboratorio di Elettronica e Sistemi</h2>\r\n"
//"<h3>RoboWiFi 2016</h3>\r\n"
//"<p id='polar' style='color:darkorange'></p>\r\n"
//"<div id='container' style='position:relative;'>"
//"<canvas width='126' height='126' style='position:absolute; left:572px; "
//"top:259px; display:none;'></canvas><canvas width='86' height='86' "
//"style='position:absolute; left:573px; top:122px; display:none;'></canvas></div>\r\n"
//			ap.send(F("<form method='get'>\r\n"));
/*			ap.send(F("<div>\r\n"));
ap.send(F("<button type='submit' name='DIR' value='U'></button>\r\n"));
ap.send(F("</div>\r\n"));
ap.send(F("<div>\r\n"));
ap.send(F("<button type='submit' name='DIR' value='L'></button>\r\n"));
ap.send(F("<button style='width: 20%; padding: 10% 0; margin: 0 3%; border-radius: 5%;' type='submit' name='DIR' value='0'></button>\r\n"));
ap.send(F("<button type='submit' name='DIR' value='R'></button>\r\n"));
ap.send(F("</div>\r\n"));
ap.send(F("<div>\r\n"));
ap.send(F("<button type='submit' name='DIR' value='D'></button>\r\n"));
ap.send(F("</div>\r\n"));
ap.send(F("<div style='height: 150px'><h4>VELOCIT&Agrave;: "));
ap.send(spd);
ap.send(F("%</h4><input type='range' min=50 max=100 value="));
ap.send(spd);
ap.send(F(" name='SPD' onchange='form.submit()'></div>\r\n"));
*/
//			ap.send(F("</form>\r\n"));
"<script>\r\n"
// Javascript starts here
// Virtualjoystick.js
"var VirtualJoystick=function(opts){\r\n"
"opts=opts||{};\r\n"
"this._container=opts.container||document.body;\r\n"
"this._strokeStyle=opts.strokeStyle||'cyan';\r\n"
"this._stickEl=opts.stickElement||this._buildJoystickStick();\r\n"
"this._baseEl=opts.baseElement||this._buildJoystickBase();\r\n"
"this._mouseSupport=opts.mouseSupport!==undefined?opts.mouseSupport:false;\r\n"
"this._stationaryBase=opts.stationaryBase||false;\r\n"
"this._baseX=this._stickX=opts.baseX||0;\r\n"
"this._baseY=this._stickY=opts.baseY||0;\r\n"
"this._limitStickTravel=opts.limitStickTravel||false;\r\n"
"this._stickRadius=opts.stickRadius!==undefined?opts.stickRadius:100;\r\n"
"this._useCssTransform=opts.useCssTransform!==undefined?opts.useCssTransform:false;\r\n"
"this._container.style.position='relative';\r\n"
"this._container.appendChild(this._baseEl);\r\n"
"this._baseEl.style.position='absolute';\r\n"
"this._baseEl.style.display='none';\r\n"
"this._container.appendChild(this._stickEl);\r\n"
"this._stickEl.style.position='absolute';\r\n"
"this._stickEl.style.display='none';\r\n"
"this._pressed=false;\r\n"
"this._touchIdx=null;\r\n"
"if(this._stationaryBase===true){\r\n"
"this._baseEl.style.display='';\r\n"
"this._baseEl.style.left=(this._baseX-this._baseEl.width/2)+'px';\r\n"
"this._baseEl.style.top=(this._baseY-this._baseEl.height/2)+'px';\r\n"
"}\r\n"
"this._transform=this._useCssTransform?this._getTransformProperty():false;\r\n"
"this._has3d=this._check3D();\r\n"
"var __bind=function(fn,me){return function(){return fn.apply(me,arguments);};};\r\n"
"this._$onTouchStart=__bind(this._onTouchStart,this);\r\n"
"this._$onTouchEnd=__bind(this._onTouchEnd,this);\r\n"
"this._$onTouchMove=__bind(this._onTouchMove,this);\r\n"
"this._container.addEventListener('touchstart',this._$onTouchStart,false);\r\n"
"this._container.addEventListener('touchend',this._$onTouchEnd,false);\r\n"
"this._container.addEventListener('touchmove',this._$onTouchMove,false);\r\n"
"if(this._mouseSupport){\r\n"
"this._$onMouseDown=__bind(this._onMouseDown,this);\r\n"
"this._$onMouseUp=__bind(this._onMouseUp,this);\r\n"
"this._$onMouseMove=__bind(this._onMouseMove,this);\r\n"
"this._container.addEventListener('mousedown',this._$onMouseDown,false);\r\n"
"this._container.addEventListener('mouseup',this._$onMouseUp,false);\r\n"
"this._container.addEventListener('mousemove',this._$onMouseMove,false);\r\n"
"}\r\n"
"}\r\n"
"VirtualJoystick.prototype.destroy=function()\r\n"
"{\r\n"
"this._container.removeChild(this._baseEl);\r\n"
"this._container.removeChild(this._stickEl);\r\n"
"\r\n"
"this._container.removeEventListener('touchstart',this._$onTouchStart,false);\r\n"
"this._container.removeEventListener('touchend',this._$onTouchEnd,false);\r\n"
"this._container.removeEventListener('touchmove',this._$onTouchMove,false);\r\n"
"if(this._mouseSupport){\r\n"
"this._container.removeEventListener('mouseup',this._$onMouseUp,false);\r\n"
"this._container.removeEventListener('mousedown',this._$onMouseDown,false);\r\n"
"this._container.removeEventListener('mousemove',this._$onMouseMove,false);\r\n"
"}\r\n"
"}\r\n"
"VirtualJoystick.touchScreenAvailable=function(){\r\n"
"return 'createTouch' in document?true:false;\r\n"
"}\r\n"
";(function(destObj){\r\n"
"destObj.addEventListener=function(event,fct){\r\n"
"if(this._events===undefined) this._events={};\r\n"
"this._events[event]=this._events[event]||[];\r\n"
"this._events[event].push(fct);\r\n"
"return fct;\r\n"
"};\r\n"
"destObj.removeEventListener=function(event,fct){\r\n"
"if(this._events===undefined) this._events={};\r\n"
"if(event in this._events===false) return;\r\n"
"this._events[event].splice(this._events[event].indexOf(fct),1);\r\n"
"};\r\n"
"destObj.dispatchEvent=function(event){\r\n"
"if(this._events===undefined) this._events={};\r\n"
"if(this._events[event]===undefined) return;\r\n"
"var tmpArray=this._events[event].slice();\r\n"
"for(var i=0;i<tmpArray.length;i++){\r\n"
"var result=tmpArray[i].apply(this,Array.prototype.slice.call(arguments,1));\r\n"
"if(result!==undefined) return result;\r\n"
"}\r\n"
"return undefined;\r\n"
"};\r\n"
"})(VirtualJoystick.prototype);\r\n"
"VirtualJoystick.prototype.deltaX=function(){return this._stickX-this._baseX;}\r\n"
"VirtualJoystick.prototype.deltaY=function(){return this._stickY-this._baseY;}\r\n"
"VirtualJoystick.prototype.up=function(){\r\n"
"if(this._pressed===false) return false;\r\n"
"var deltaX=this.deltaX();\r\n"
"var deltaY=this.deltaY();\r\n"
"if(deltaY>=0) return false;\r\n"
"if(Math.abs(deltaX)>2*Math.abs(deltaY)) return false;\r\n"
"return true;\r\n"
"}\r\n"
"VirtualJoystick.prototype.down=function(){\r\n"
"if(this._pressed===false) return false;\r\n"
"var deltaX=this.deltaX();\r\n"
"var deltaY=this.deltaY();\r\n"
"if(deltaY<=0) return false;\r\n"
"if(Math.abs(deltaX)>2*Math.abs(deltaY)) return false;\r\n"
"return true;\r\n"
"}\r\n"
"VirtualJoystick.prototype.right=function(){\r\n"
"if(this._pressed===false) return false;\r\n"
"var deltaX=this.deltaX();\r\n"
"var deltaY=this.deltaY();\r\n"
"if(deltaX<=0) return false;\r\n"
"if(Math.abs(deltaY)>2*Math.abs(deltaX)) return false;\r\n"
"return true;\r\n"
"}\r\n"
"VirtualJoystick.prototype.left=function(){\r\n"
"if(this._pressed===false) return false;\r\n"
"var deltaX=this.deltaX();\r\n"
"var deltaY=this.deltaY();\r\n"
"if(deltaX>=0) return false;\r\n"
"if(Math.abs(deltaY)>2*Math.abs(deltaX)) return false;\r\n"
"return true;\r\n"
"}\r\n"
"VirtualJoystick.prototype._onUp=function(){\r\n"
"this._pressed=false;\r\n"
"this._stickEl.style.display='none';\r\n"
"if(this._stationaryBase==false){\r\n"
"this._baseEl.style.display='none';\r\n"
"this._baseX=this._baseY=0;\r\n"
"this._stickX=this._stickY=0;\r\n"
"}\r\n"
"}\r\n"
"VirtualJoystick.prototype._onDown=function(x,y){\r\n"
"this._pressed=true;\r\n"
"if(this._stationaryBase==false){\r\n"
"this._baseX=x;\r\n"
"this._baseY=y;\r\n"
"this._baseEl.style.display='';\r\n"
"this._move(this._baseEl.style,(this._baseX-this._baseEl.width/2),(this._baseY-this._baseEl.height/2));\r\n"
"}\r\n"
"this._stickX=x;\r\n"
"this._stickY=y;\r\n"
"if(this._limitStickTravel===true){\r\n"
"var deltaX=this.deltaX();\r\n"
"var deltaY=this.deltaY();\r\n"
"var stickDistance=Math.sqrt((deltaX*deltaX)+(deltaY*deltaY));\r\n"
"if(stickDistance>this._stickRadius){\r\n"
"var stickNormalizedX=deltaX/stickDistance;\r\n"
"var stickNormalizedY=deltaY/stickDistance;\r\n"
"this._stickX=stickNormalizedX*this._stickRadius+this._baseX;\r\n"
"this._stickY=stickNormalizedY*this._stickRadius+this._baseY;\r\n"
"}\r\n"
"}\r\n"
"this._stickEl.style.display='';\r\n"
"this._move(this._stickEl.style,(this._stickX-this._stickEl.width/2),(this._stickY-this._stickEl.height/2));\r\n"
"}\r\n"
"VirtualJoystick.prototype._onMove=function(x,y){\r\n"
"if(this._pressed===true){\r\n"
"this._stickX=x;\r\n"
"this._stickY=y;\r\n"
"if(this._limitStickTravel===true){\r\n"
"var deltaX=this.deltaX();\r\n"
"var deltaY=this.deltaY();\r\n"
"var stickDistance=Math.sqrt((deltaX*deltaX)+(deltaY*deltaY));\r\n"
"if(stickDistance>this._stickRadius){\r\n"
"var stickNormalizedX=deltaX/stickDistance;\r\n"
"var stickNormalizedY=deltaY/stickDistance;\r\n"
"this._stickX=stickNormalizedX*this._stickRadius+this._baseX;\r\n"
"this._stickY=stickNormalizedY*this._stickRadius+this._baseY;\r\n"
"}\r\n"
"}\r\n"
"this._move(this._stickEl.style,(this._stickX-this._stickEl.width/2),(this._stickY-this._stickEl.height/2));\r\n"
"}\r\n"
"}\r\n"
"VirtualJoystick.prototype._onMouseUp=function(event){\r\n"
"return this._onUp();\r\n"
"}\r\n"
"VirtualJoystick.prototype._onMouseDown=function(event){\r\n"
"event.preventDefault();\r\n"
"var x=event.clientX;\r\n"
"var y=event.clientY;\r\n"
"return this._onDown(x,y);\r\n"
"}\r\n"
"VirtualJoystick.prototype._onMouseMove=function(event){\r\n"
"var x=event.clientX;\r\n"
"var y=event.clientY;\r\n"
"return this._onMove(x,y);\r\n"
"}\r\n"
"VirtualJoystick.prototype._onTouchStart=function(event){\r\n"
"if(this._touchIdx!==null) return;\r\n"
"var isValid=this.dispatchEvent('touchStartValidation',event);\r\n"
"if(isValid===false) return;\r\n"
"this.dispatchEvent('touchStart',event);\r\n"
"event.preventDefault();\r\n"
"var touch=event.changedTouches[0];\r\n"
"this._touchIdx=touch.identifier;\r\n"
"var x=touch.pageX;\r\n"
"var y=touch.pageY;\r\n"
"return this._onDown(x,y);\r\n"
"}\r\n"
"VirtualJoystick.prototype._onTouchEnd=function(event){\r\n"
"if(this._touchIdx===null) return;\r\n"
"this.dispatchEvent('touchEnd',event);\r\n"
"var touchList=event.changedTouches;\r\n"
"for(var i=0;i<touchList.length&&touchList[i].identifier!==this._touchIdx;i++);\r\n"
"if(i===touchList.length) return;\r\n"
"this._touchIdx=null;\r\n"
"event.preventDefault();\r\n"
"return this._onUp();\r\n"
"}\r\n"
"VirtualJoystick.prototype._onTouchMove=function(event){\r\n"
"if(this._touchIdx===null) return;\r\n"
"var touchList=event.changedTouches;\r\n"
"for(var i=0;i<touchList.length&&touchList[i].identifier!==this._touchIdx;i++);\r\n"
"if(i===touchList.length) return;\r\n"
"var touch=touchList[i];\r\n"
"event.preventDefault();\r\n"
"var x=touch.pageX;\r\n"
"var y=touch.pageY;\r\n"
"return this._onMove(x,y);\r\n"
"}\r\n"
"VirtualJoystick.prototype._buildJoystickBase=function(){\r\n"
"var canvas=document.createElement('canvas');\r\n"
"canvas.width=126;\r\n"
"canvas.height=126;\r\n"
"var ctx=canvas.getContext('2d');\r\n"
"ctx.beginPath();\r\n"
"ctx.strokeStyle=this._strokeStyle;\r\n"
"ctx.lineWidth=6;\r\n"
"ctx.arc(canvas.width/2,canvas.width/2,40,0,Math.PI*2,true);\r\n"
"ctx.stroke();\r\n"
"ctx.beginPath();\r\n"
"ctx.strokeStyle=this._strokeStyle;\r\n"
"ctx.lineWidth=2;\r\n"
"ctx.arc(canvas.width/2,canvas.width/2,60,0,Math.PI*2,true);\r\n"
"ctx.stroke();\r\n"
"return canvas;\r\n"
"}\r\n"
"VirtualJoystick.prototype._buildJoystickStick=function(){\r\n"
"var canvas=document.createElement('canvas');\r\n"
"canvas.width=86;\r\n"
"canvas.height=86;\r\n"
"var ctx=canvas.getContext('2d');\r\n"
"ctx.beginPath();\r\n"
"ctx.strokeStyle=this._strokeStyle;\r\n"
"ctx.lineWidth=6;\r\n"
"ctx.arc(canvas.width/2,canvas.width/2,40,0,Math.PI*2,true);\r\n"
"ctx.stroke();\r\n"
"return canvas;\r\n"
"}\r\n"
"VirtualJoystick.prototype._move=function(style,x,y){\r\n"
"if(this._transform){\r\n"
"if(this._has3d){\r\n"
"style[this._transform]='translate3d('+x+'px,'+y+'px,0)';\r\n"
"}else{\r\n"
"style[this._transform]='translate('+x+'px,'+y+'px)';\r\n"
"}\r\n"
"}else{\r\n"
"style.left=x+'px';\r\n"
"style.top=y+'px';\r\n"
"}\r\n"
"}\r\n"
"VirtualJoystick.prototype._getTransformProperty=function(){\r\n"
"var styles=[\r\n"
"'webkitTransform',\r\n"
"'MozTransform',\r\n"
"'msTransform',\r\n"
"'OTransform',\r\n"
"'transform'\r\n"
"];\r\n"
"var el=document.createElement('p');\r\n"
"var style;\r\n"
"for(var i=0;i<styles.length;i++){\r\n"
"style=styles[i];\r\n"
"if(null!=el.style[style]){\r\n"
"return style;\r\n"
"}\r\n"
"}\r\n"
"}\r\n"
"VirtualJoystick.prototype._check3D=function(){\r\n"
"var prop=this._getTransformProperty();\r\n"
"if(!prop||!window.getComputedStyle) return module.exports=false;\r\n"
"var map={"
"webkitTransform:'-webkit-transform',"
"OTransform:'-o-transform',"
"msTransform:'-ms-transform',"
"MozTransform:'-moz-transform',"
"transform:'transform'"
"};\r\n"
"var el=document.createElement('div');"
"el.style[prop]='translate3d(1px,1px,1px)';"
"document.body.insertBefore(el,null);"
"var val=getComputedStyle(el).getPropertyValue(map[prop]);"
"document.body.removeChild(el);"
"var exports=null!=val&&val.length&&'none'!=val;"
"return exports;"
"}\r\n"

"var joy=new VirtualJoystick({strokeStyle:'dodgerblue',"
//container:document.getElementById('container'),"
"stationaryBase:true,baseX:document.body.clientWidth/2,baseY:document.body.clientHeight/2,"
"limitStickTravel:true,stickRadius:120,mouseSupport:true});\r\n"

"var busy=false;\r\n"
"var end=false;\r\n"
"var xhr=new XMLHttpRequest();\r\n"
"var dx=0,dy=0;\r\n"

"xhr.onreadystatechange=function(){"
"if(this.readyState==XMLHttpRequest.DONE&&this.status==200&&this.responseText=='OK') {busy=false;"
"if(end) {sendCoord(0,0);end=false;}}"
"}\r\n"

"function sendCoord(dex,dey){\r\n"
//"if(Math.abs(dex-dx)>5||Math.abs(-dey-dy)>5||dex==0||dey==0){"
"dx=dex;dy=-dey;\r\n"
"rho=Math.sqrt(dx*dx+dy*dy);\r\n"
"if(dx==0&&dy==0) phi=0;\r\n"
"else if(dx==0&&dy>0) phi=90;\r\n"
"else if(dx==0&&dy<0) phi=270;\r\n"
"else if(dx>0&&dy>=0) phi=Math.atan(dy/dx)*180/Math.PI;\r\n"
"else if(dx<0) phi=180+Math.atan(dy/dx)*180/Math.PI;\r\n"
"else if(dx>0&&dy<0) phi=360+Math.atan(dy/dx)*180/Math.PI;\r\n"
//"document.getElementById('polar').innerHTML=Math.round(rho)+';'+Math.round(phi)+' - '+send;\r\n"
"busy=true;\r\n"
"xhr.open('POLAR',Math.round(rho)+','+Math.round(phi),true);\r\n"
"xhr.send();\r\n"
"}\r\n"

"document.addEventListener('touchstart',function(){"
"sendCoord(joy.deltaX(),joy.deltaY());"
"});\r\n"

"document.addEventListener('touchend',function(){"
"if(!busy) sendCoord(0,0);"
"else end=true;"
"});\r\n"

"document.addEventListener('touchmove',function(){"
//"if(Math.abs(joy.deltaX()-dx)>10||Math.abs(-joy.deltaY()-dy)>10)\r\n"
"if(!busy) sendCoord(joy.deltaX(),joy.deltaY());"
"});\r\n"

"</script>\r\n"
// Javascript ends here
"</body>\r\n"
// Body ends here
"</html>\r\n";
// ***** WEBPAGE ENDS HERE *****
