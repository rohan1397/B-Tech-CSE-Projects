
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<script>

function validate(){
var username=document.form.user.value;
var password=document.form.pass.value;
if(username==""){
 alert("Enter Username!");
  return false;
}
if(password==""){
 alert("Enter Password!");
  return false;
}
return true;
}
</script>
<style type="text/css">
.cssmenu {
	width: 100%;
	height: 27px;
	margin: 0;
	padding: 0;
	background: #000000 url(menu_assets/images/bg-bubplastic.gif) top left repeat-x;
}
.cssmenu ul {
	list-style: none;
	margin: 0;
	padding: 0;
}
.cssmenu ul li {
	float: left;
	margin: 0;
	padding: 0;
	background: transparent url(menu_assets/images/bg-bubplastic-button.gif) top left no-repeat;
}

.cssmenu ul li a {
	display: block;
	height: 27px;
	padding-left: 35px;
	float: left;
	text-transform: uppercase;
	font-family: 'Helvetica Neue',helvetica,'microsoft sans serif',arial,sans-serif;
	font-size: 70%;
	color: #FFFFFF;
	text-decoration: none;
}

.cssmenu ul li a span {
	display: block;
	float: left;
	height: 22px;
	padding-top: 5px;
	padding-right: 35px;
	background: transparent url(menu_assets/images/bg-bubplastic-button.gif) top right no-repeat;
	cursor: pointer;
}


.cssmenu ul li a:hover,
.cssmenu ul li.active a {
	background: transparent url(menu_assets/images/bg-bubplastic-h-orange.gif) top left no-repeat;
}
.cssmenu ul li a:hover span,
.cssmenu ul li.active a span {
	background: transparent url(menu_assets/images/bg-bubplastic-h-orange.gif) top right no-repeat;
}

</style>
<div align="center">
 <div class='cssmenu'>
<ul>
   <li class='active '><a href='index.jsp'><span>Home</span></a></li>
   <li><a href='login.jsp'><span>Login</span></a></li>
   <li><a href='index.jsp'><span>About</span></a></li>
   <li><a href='#'><span>Contact</span></a></li>
</ul>
</div>
</div>
<form name="form" method="post" action="checkc.jsp" onsubmit="javascript:return validate();">
    
<div align="center">
<h1>Sign Up</h1>
<table>
<tr><td bgcolor="#FF9900">Username:</td><td bgcolor="#33CCCC"><input type="text" name="user"></td></tr>
<tr><td bgcolor="#FF9900">Password:</td><td bgcolor="#33CCCC"><input type="password" name="pass"></td></tr>
<tr><td bgcolor="#FF9900">Email:</td><td bgcolor="#33CCCC"><input type="email" name="mail"></td></tr>
<tr><td bgcolor="#FF9900">Address:</td><td bgcolor="#33CCCC"><input type="text" name="add"></td></tr>
<tr><td bgcolor="#FF9900">City:</td><td bgcolor="#33CCCC"><input type="text" name="City"></td></tr>
<tr><td bgcolor="#FF9900">Pincode:</td><td bgcolor="#33CCCC"><input type="text" name="Pincode"></td></tr>
<tr><td bgcolor="#FF9900">State:</td><td bgcolor="#33CCCC"><input type="text" name="state"></td></tr>
<tr><td bgcolor="#FF9900">Phone Number:</td><td bgcolor="#33CCCC"><input type="text" name="phone"></td></tr>

<tr><td></td><td><input type="submit" value="Submit"></td></tr>
</table>
</div>
</form>
</html>