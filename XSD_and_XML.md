# Tutorial from YouTube: XML and XSD: How do they work?
## 1. XSD Overview: Why use XSD? What is a simple type?
1. XML Schemas Definition
2. Create XML files and validate XML files
3. Types available:
    * xs:string
    * xs:decimal
    * xs:integer
    * xs:boolean
    * xs:date
    * xs:time
## 2. Create and Link an XSD file to an XML file in Notepad++
1. XSD sample file
```xml
<?xml version="1.0" encoding="UTF-8"?>
    <xs:schema xmlns:xs="http://www.w3.org/2001/XMLSchema">
	<xs:element name="plant"> <!-- plant is the root element -->
	    <!-- XSD validation rules go inside this xs:element tag-->
    </xs:element>
</xs:schema>
```
2. XML sample file
```xml
<?xml version="2.0"?>
    <plant xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
        xsi:noNamespaceSchemaLocation="plants.xsd">
    <!-- start the root element -->
    <!-- Self Notes: link to the XSD file.
	Since the XSD file at the same location as the XML file, there is no path in this case. -->
        <!-- All payload data belongs here -->
    <genus>Cercis</genus> <!-- a child element called genus and the content is Cercis -->
</plant>

```
## 3. Add simple rules to an XSD, validate XML file
1. XSD sample file
```xml
<?xml version="1.0" encoding="UTF-8"?><xs:schema xmlns:xs="http://www.w3.org/2001/XMLSchema">
<xs:element name="plant">
	<xs:complexType> <!-- the children elements are complexType -->
		<xs:sequence> <!-- the children must follow the sequence -->
			<xs:element name="genus" type="xs:string"/>
			<xs:element name="species" type="xs:string"/ minOccurs="0">
			<!-- Self Notes: minOccurs="0" means the element is not required -->
			<xs:element name="common_name" type="xs:string"/ minOccurs="0">
			<xs:element name="cultivar" type="xs:string"/ minOccurs="0">
		</xs:sequence>
	</xs:complexType>
</xs:element></xs:schema>
```
## 4. Specify max length in XSD, max number for an integer
1. XSD sample file
```xml
<?xml version="1.0" encoding="UTF-8"?>
<xs:schema xmlns:xs="http://www.w3.org/2001/XMLSchema">
	<xs:element name="plant">
		<xs:complexType>
			<xs:sequence>
				<xs:element name="genus">
				<!-- Self Notes: change single line to multiple lines of element -->
					<xs:simpleType>
						<xs:restriction base="xs:string">
						<!-- Self Notes: add restrictions -->
							<xs:maxLength value="60"/>
							<!-- Self Notes: max length of a string is 60 -->
						</xs:restriction>
					</xs:simpleType>
				</xs:element>
				<xs:element name="species" minOccurs="0">
					<xs:simpleType>
						<xs:restriction base="xs:string">
							<xs:maxLength value="60"/>
						</xs:restriction>
					</xs:simpleType>
				</xs:element>
				<xs:element name="cultivar" minOccurs="0">
					<xs:simpleType>
						<xs:restriction base="xs:string">
							<xs:maxLength value="60"/>
						</xs:restriction>
					</xs:simpleType>
				</xs:element>
				<xs:element name="common_name" minOccurs="0">
					<xs:simpleType>
						<xs:restriction base="xs:string">
							<xs:maxLength value="100"/>
						</xs:restriction>
					</xs:simpleType>
				</xs:element>
				<xs:element name="height" minOccurs="0">
					<xs:simpleType>
						<xs:restriction base="xs:integer">
							<xs:maxInclusive value="100"/>
							<!-- Self Notes: max number of an integer is 100 -->
						</xs:restriction>
					</xs:simpleType>
				</xs:element>
			</xs:sequence>
		</xs:complexType>
	</xs:element>
</xs:schema>

```
## 5. Using date, boolean, and default in XSD to validate XML
1. Set default values
```xml
<xs:element name="height" minOccurs="0" default="0">
	<!-- Self Notes: set default value as 0 -->
	<xs:simpleType>
		<xs:restriction base="xs:integer">
			<xs:maxInclusive value="100"/>
		</xs:restriction>
	</xs:simpleType>
</xs:element>
```
2. Set type to date
```xml
<xs:element name="begin_bloom_date" type="xs:date" minOccurs="0"/> 
```
3. Set type to boolean
```xml
<xs:element name="edible" type="xs:boolean" minOccurs="0"/>
```