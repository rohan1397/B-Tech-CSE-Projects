<%-- 
    Document   : check
    Created on : May 15, 2012, 12:18:10 PM
    Author     : Diaa
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%@page import="java.sql.*"%>

<%
String user=request.getParameter("user");
String pass=request.getParameter("pass");
 Class.forName("com.mysql.jdbc.Driver").newInstance();
    Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/onlineshop","root","root");  
           Statement st=con.createStatement();
           ResultSet rs=st.executeQuery("select CustomerId,CustomerPass from signup where CustomerId='"+user+"' and CustomerPass='"+pass+"'");
          int count=0;
          while(rs.next())
          {

                   count++;
          }

                    if(count>0)
          {
            out.println("welcome "+user);
            response.sendRedirect("index.jsp?msg=welcome "+user +"   <a href=\"index.jsp\">loged out</a>");
            session.removeAttribute("user");
          }
          else
          {
                       response.sendRedirect("loginC.jsp?msg=Invalid Username or Password");
          }
%>
