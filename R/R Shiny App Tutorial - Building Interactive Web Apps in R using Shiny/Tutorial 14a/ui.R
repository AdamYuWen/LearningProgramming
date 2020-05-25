library(shiny)

shinyUI(fluidPage(
  titlePanel(title = h4("Tutorial 14a", align = "center")),

  sidebarLayout(
    sidebarPanel(
      textInput(inputId = "first_name",
                label = "Enter your first name",
                value = ""),

      textInput(inputId = "last_name",
                label = "Enter your last name",
                value = ""),

      actionButton(inputId = "action",
                   label = "Update last name!"),
      p("Click on the Update button to update and display the last name.
        Here the reactivness of the input widget is controlled by actionButton
        on the client and isolate on the server side")
    ),

    mainPanel(
      textOutput("my_first_name"),
      textOutput("my_last_name")
    )
  )
))
