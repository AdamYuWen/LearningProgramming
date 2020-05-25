library(shiny)

shinyUI(fluidPage(
  titlePanel(title = h4("Tutorial 12a", align = "center")),

  sidebarLayout(
    sidebarPanel(
      textInput(inputId = "first_name",
                label = "Enter your first name"),

      textInput(inputId = "last_name",
                label = "Enter your last name"),

      # The submit button works automatically.
      submitButton(text = "Update!"),
      # p is for printing.
      p("Click on the Update button to display the first and last name entered
        by the user. Here the reactiveness of")
    ),

    mainPanel(
      textOutput("first_name"),
      textOutput("last_name")
    )
  )
))
