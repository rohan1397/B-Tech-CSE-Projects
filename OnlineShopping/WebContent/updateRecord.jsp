<%-- 
    Document   : updateRecord
    Created on : May 15, 2012, 4:05:32 PM
    Author     : Diaa
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%@ page language="java" import="java.sql.*" errorPage="" %>
<%
  Connection conn = null;
        
  Class.forName("com.mysql.jdbc.Driver").newInstance();
  conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/onlineshop","root","root");
        
  PreparedStatement psUpdateRecord=null;
  String sqlUpdateRecord=null;
        
  String ProID=request.getParameter("UPID");
  String ProName=request.getParameter("UPname");
  String ProQuant=request.getParameter("UPQuant");
  String ProCat=request.getParameter("UPcat");
  String ProPrice=request.getParameter("UPprice");
  
        
  try
  {
      
   sqlUpdateRecord="update products set ProdcutName = ?, ProductQuant = ?, ProductCat = ?, ProductPrice = ?  where ProductID = ?";
   psUpdateRecord=conn.prepareStatement(sqlUpdateRecord);
   psUpdateRecord.setString(1,ProID);
   psUpdateRecord.setString(2,ProName);
   psUpdateRecord.setString(3,ProQuant);
   psUpdateRecord.setString(4,ProCat);
   psUpdateRecord.setString(5,ProPrice);
   
            
   psUpdateRecord.executeUpdate();
  }
  catch(Exception e)
  {
      response.sendRedirect("admin.jsp");//// On error it will send back to addRecord.jsp page
  }
        
    try{
      if(psUpdateRecord!=null)
      {
       psUpdateRecord.close();
      }
      
      if(conn!=null)
      {
       conn.close();
      }
    }
    catch(Exception e)
    {
      e.printStackTrace(); 
    }
%>
<html>
    <head>
      <meta http-equiv="REFRESH" content="3;url=/onlineshopping/login.jsp">
    </head>
<body>
Data is Updated successfully.<br>
You will be redirected to the Previous Page in 3 seconds.....

</body>
</html>
