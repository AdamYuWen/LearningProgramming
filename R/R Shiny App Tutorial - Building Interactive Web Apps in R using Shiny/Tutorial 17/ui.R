library(shiny)

shinyUI(fluidPage(
  titlePanel(title = h4("Tutorial 17", align = "center")),

  sidebarLayout(
    sidebarPanel(
      fileInput(inputId = "file",
                label = "Upload the file",
                multiple = TRUE),
      helpText("Default max. file size is 5MB"),

      tags$hr(),
      h5(helpText("Select the read.table parameters below")),

      checkboxInput(inputId = "header", label = "Header", value = FALSE),
      checkboxInput(inputId = "stringAsFactors",
                    label = "stringAsFactors", value = FALSE),

      br(),
      radioButtons(inputId = "separator",
                   label = "Separator",
                   choices = c("Comma" = ",",
                               "Semicolon" = ";",
                               "Tab" = "\t",
                               "Space" = " "),
                   selected = ","),

      uiOutput("select_file"),

      # Add styles to UI
      # Change background color, font style, border style
      tags$style("body{background-color: linen; color: brown}"),
      tags$style(".control-label{font-style: oblique; border-style: solid}")
    ),

    mainPanel(
      uiOutput(outputId = "tab")
    )
  )
))
