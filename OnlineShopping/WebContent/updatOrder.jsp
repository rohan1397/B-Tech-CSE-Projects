
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%@ page language="java" import="java.sql.*" errorPage="" %>
<%
  Connection conn = null;
        
  Class.forName("com.mysql.jdbc.Driver").newInstance();
  conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/onlineshop","root","root");
        
  PreparedStatement psInsertRecord=null;
  String sqlInsertRecord=null;
        
  String CustID=request.getParameter("CustId");
  String CNAME=request.getParameter("CustName");
  String PHONE=request.getParameter("CustPhone");
  String MAIL=request.getParameter("CustMail");
  String ADDR=request.getParameter("CustAdd");
  String OrPID=request.getParameter("OPID");
  
        
  try
  {
   sqlInsertRecord="insert into ordercustomer (CustID, CustName,CustPhone, CustMail,ProductId,CustAdd) values('?','?','?','?','?',?')";
   psInsertRecord=conn.prepareStatement(sqlInsertRecord);
   psInsertRecord.setString(1,CustID);
   psInsertRecord.setString(2,CNAME);
   psInsertRecord.setString(3,PHONE);
   psInsertRecord.setString(4,MAIL);
   psInsertRecord.setString(5,OrPID);
   psInsertRecord.setString(6,ADDR);
   //psInsertRecord.setString(6,PHONE);
   
            
   psInsertRecord.executeUpdate();
  }
  catch(Exception e)
  {
      response.sendRedirect("buy.jsp");
      //// On error it will send back to addRecord.jsp page
  }
  

      
    try{
      if(psInsertRecord!=null)
      {
       psInsertRecord.close();
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
      <meta http-equiv="REFRESH" content="3;url=/onlineshopping/index.jsp">
    </head>
<body>
Ordered successfully. Thank YOU for Ordering and visiting Our Web site<br>
You will be redirected to the Main Page in 3 seconds.....
</body>
</html>