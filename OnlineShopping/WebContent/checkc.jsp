<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%@ page language="java" import="java.sql.*" errorPage="" %>

<%
  Connection conn = null;
        
  Class.forName("com.mysql.jdbc.Driver");
  conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/onlineshop","root","root");
        
  PreparedStatement psInsertRecord=null;
  String sqlInsertRecord=null;
        
  String Cuser=request.getParameter("user");
  String Cpass=request.getParameter("pass");
  String Cmail=request.getParameter("mail");
  String Cadd=request.getParameter("add");
  String Ccity=request.getParameter("City");
  String Cstate=request.getParameter("state");
  String Cpincode=request.getParameter("Pincode");
  String Cphone=request.getParameter("phone");
  out.println(Cpass);
        
  try
  {
   //sqlInsertRecord="insert into products (ProductID, ProdcutName, ProductQuant, ProductCat,  ProductPrice) values('"+ProID+"','"+ProName+"',+'"+ProQuant+"','"+ProCat+"','"+ProPrice+"')";
   //sqlInsertRecord="insert into signup (ProductID, ProdcutName, ProductQuant, ProductCat,  ProductPrice) values(?,?,?,?,?)";
   sqlInsertRecord="insert into sign_up(CustomerId,CustomerPass,CustomerMail,CustomerAdd,CustomerCity,CustomerState,CustomerPc,CustomerPhone)values('?','?','?','?','?','?','?','?')";
   psInsertRecord=conn.prepareStatement(sqlInsertRecord);
   psInsertRecord.setString(1,Cuser);
   psInsertRecord.setString(2,Cpass);
   psInsertRecord.setString(3,Cmail);
   psInsertRecord.setString(4,Cadd);
   psInsertRecord.setString(5,Ccity);
   psInsertRecord.setString(6,Cstate);
   psInsertRecord.setString(7,Cpincode);
   psInsertRecord.setString(8,Cphone);
   psInsertRecord.executeUpdate();
  }
  catch(Exception e)
  {
   e.printStackTrace();
	  //   response.sendRedirect("index.jsp");//// On error it will send back to addRecord.jsp page
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
Data is saved successfully.<br>
You will be redirected to the Previous Page in 3 seconds.....
</body>
</html>