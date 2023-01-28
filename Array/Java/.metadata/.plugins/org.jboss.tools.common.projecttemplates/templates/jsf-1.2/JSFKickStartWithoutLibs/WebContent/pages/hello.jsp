<%@ taglib uri="http://java.sun.com/jsf/core" prefix="f"%>
<%@ taglib uri="http://java.sun.com/jsf/html" prefix="h"%>

<f:loadBundle var="Message" basename="demo.Messages" />

<html>
	<head>
		<title>Hello!</title>
	</head>

	<body>
		<f:view>
			<h3>
				<h:outputText value="#{Message.hello_message}" />,
				<h:outputText value="#{user.name}" />!
			</h3>
		</f:view>
	</body>

</html>