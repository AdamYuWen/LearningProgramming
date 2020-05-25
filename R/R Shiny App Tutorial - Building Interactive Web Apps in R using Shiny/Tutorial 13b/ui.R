library(shiny)

shinyUI(fluidPage(
  titlePanel(title = h4("Tutorial 13b", align = "center")),

  sidebarLayout(
    sidebarPanel(
      numericInput(inputId = "n",
                   label = "Enter the number of tabs needed",
                   value = 1)
    ),

    mainPanel(
      # Based on the input, show tabs.
      uiOutput("tabs")
    )
  )
))
