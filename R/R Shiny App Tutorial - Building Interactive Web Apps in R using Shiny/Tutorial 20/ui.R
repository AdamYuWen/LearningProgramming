library(shiny)

shinyUI(fluidPage(
  titlePanel(title = h4("Tutorial 20", align = "center")),

  sidebarLayout(
    sidebarPanel(
      selectInput(inputId = "Year",
                  label = "Year",
                  choices = unique(data$Year)),

      # The choices are conditional, so it is empty for now.
      selectInput(inputId = "Month",
                  label = "Month",
                  choices = "",
                  selected = ""),

      selectInput(inputId = "Name",
                  label = "Name",
                  choices = "",
                  selected = "")
    ),

    mainPanel(
      tableOutput("dataset")
    )
  )
))
