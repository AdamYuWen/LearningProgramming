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
<?xml version="1.0"?>
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
<?xml version="1.0" encoding="UTF-8"?>
<xs:schema xmlns:xs="http://www.w3.org/2001/XMLSchema">
	<xs:element name="plant">
		<xs:complexType> <!-- the children elements are complexType -->
			<xs:sequence> <!-- the children must follow the sequence -->
				<xs:element name="genus" type="xs:string"/>
				<xs:element name="species" type="xs:string" minOccurs="0"/>
				<!-- Self Notes: minOccurs="0" means the element is not required -->
				<xs:element name="common_name" type="xs:string" minOccurs="0"/>
				<xs:element name="cultivar" type="xs:string" minOccurs="0"/>
			</xs:sequence>
		</xs:complexType>
	</xs:element>
</xs:schema>
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
							<!-- Self Notes: max number of an integer is 100.
							maxInclusive means including 100.
							maxExclusive means not including 100. -->
						</xs:restriction>
					</xs:simpleType>
				</xs:element>
			</xs:sequence>
		</xs:complexType>
	</xs:element>
</xs:schema>
```
## 5. Using date, boolean, and default in XSD to validate XML
1. Set default values (XSD)
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
2. Set type to date (XSD)
```xml
<xs:element name="begin_bloom_date" type="xs:date" minOccurs="0"/>
```
3. Set type to boolean (XSD)
```xml
<xs:element name="edible" type="xs:boolean" minOccurs="0"/>
```
## 6. Use xs:enumeration in XSD to restrict values in XML doc
1. Set type to enumeration (XSD)
```xml
<xs:element name="sun_tolerance">
	<xs:simpleType>
		<xs:restriction base="xs:string">
			<xs:enumeration value="full_sun"/>
			<xs:enumeration value="part_sun"/>
			<xs:enumeration value="part_shade"/>
			<xs:enumeration value="full_shade"/>
		</xs:restriction>
	</xs:simpleType>
</xs:element>
```
## 7. Define our own type in XSD, create repeating group
1. Define a new type (XSD)
```xml
<xs:complexType name="specimenType">
<!-- Self Notes: Self defined type -->
	<xs:sequence>
		<xs:element name="latitude" type="xs:decimal" minOccurs="0"/>
		<xs:element name="longitude" type="xs:decimal" minOccurs="0"/>
		<xs:element name="planted_by" minOccurs="0">
			<xs:simpleType>
				<xs:restriction base="xs:string">
					<xs:maxLength value="255"/>
				</xs:restriction>
			</xs:simpleType>
		</xs:element>
		<xs:element name="comments" minOccurs="0">
			<xs:simpleType>
				<xs:restriction base="xs:string">
					<xs:maxLength value="1024"/>
				</xs:restriction>
			</xs:simpleType>
		</xs:element>
	</xs:sequence>
</xs:complexType>
```
2. Use self defined type and create repeating group (XSD)
```xml
<xs:element name="specimens" minOccurs="0">
<!-- Self Notes: Here is our own type -->
	<xs:complexType>
		<xs:sequence>
			<xs:element name="specimen" type="specimenType"
			minOccurs="1" maxOccurs="unbounded"/>
			<!-- Self Notes: "specimens" is not require.
			However, once "specimens" includes, at least
			one specimen should have. -->
		</xs:sequence>
	</xs:complexType>
</xs:element>
```
3. Sample XML file
```xml
<specimen>
	<latitude>39.47</latitude>
	<longitude>-84.51</longitude>
	<planted_by>Brandan Jones</planted_by>
	<comments>Beautiful tree!</comments>
</specimen>
<specimen>
	<latitude>52.40</latitude>
	<longitude>1.00</longitude>
	<planted_by>Joe Bloggs</planted_by>
	<comments>RBG Kew</comments>
</specimen>
```
## 8. Overview and Discussion of XPath
1. [Formating xml](https://codebeautify.org/xmlviewer)
2. [Online XPath](https://www.freeformatter.com/xpath-tester.html)
## 9. XPath examples and demonstrations in XML
1. XPath examples
   - `/plant/specimens`
   - `/plant/specimens/specimen[1]`
   - `/plant/specimens/specimen[last()]`
   - `/plant/specimens/specimen[latitude>0]`
   - `/plant/specimens/specimen[latitude>50]/../..`
2. Not sure about where it is
   - `//latitude`
   - `//..[latitude>0]/latitude`: Don't know about the parenet, get latitude only when latitude > 0
## 10. Overview of XSLT
1. Steps from XML to XSL
   1. Start with an XML document.
   2. Create and XSL document that contains the desired destination format.
   3. Reference the XSL file from the XML file.
   4. Use XPath to pull XML into XSL.
   5. Open the XML file in a browser.
## 11. Transform XML to HTML by using XSL/XSLT
## 12. Uploading and Saving a file in C# .net; Validating XML
## 13. Validating XML against XSD in C# using XmlREader