
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%@page import="java.sql.*"%>

<%
String user=request.getParameter("user");
String pass=request.getParameter("pass");
 Class.forName("com.mysql.jdbc.Driver").newInstance();
 
    Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/onlineshop","root","root");  
           Statement st=con.createStatement();
           ResultSet rs=st.executeQuery("select AdminName,AdminPass from admins where AdminName='"+user+"' and AdminPass='"+pass+"'");
          int count=0;
          while(rs.next())
          {

                   count++;
          }

                    if(count>0)
          {
            out.println("welcome "+user);
            response.sendRedirect("admin.jsp?msg=welcome "+user +"   <a href=\"index.jsp\">loged out</a>");
            session.removeAttribute("user");
          }
          else
          {
                       response.sendRedirect("login.jsp?msg=Invalid Username or Password");
          }
%>
<html>
 <head>
      <meta http-equiv="REFRESH" content="3;url=/onlineshopping/index.jsp">
    </head>
<body>
Data is saved successfully.<br>
You will be redirected to the Previous Page in 3 seconds.....
</body>
</html>