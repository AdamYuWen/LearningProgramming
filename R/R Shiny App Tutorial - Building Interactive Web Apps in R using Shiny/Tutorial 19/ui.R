library(shiny)

shinyUI(fluidPage(
  titlePanel(title = h4("Tutorial 19", align = "center")),

  sidebarLayout(
    sidebarPanel(
      # tabselected is set up in mainPanel, which is related to value.
      # condition is an important parameter.
      # In the condition, it is "." instead of "$".
      conditionalPanel(condition = "input.tabselected == 1",
                       h4("Demo conditionalPanel()")),

      conditionalPanel(condition = "input.tabselected == 2",
                       selectInput(inputId = "dataset",
                                   label = "select the desired dataset",
                                   # list all datasets
                                   choices = ls("package:datasets"),
                                   selected = "mtcars"),
                       # The default values are set as 1, 2, 3.
                       radioButtons(inputId = "choice",
                                    label = "Choose an option",
                                    choices = c("Dataset" = 1,
                                                "Structure" = 2,
                                                "Summary" = 3))),

      conditionalPanel(condition = "input.tabselected == 3",
                       uiOutput("var_x"), uiOutput("var_y"))
    ),

    mainPanel(
      tabsetPanel(
        tabPanel("About", value = 1,
                 helpText("conditionalPanel(conditional, ...")),
        tabPanel("Data", value = 2,
                 # choice is set up in radioButtons.
                 conditionalPanel(condition = "input.choice == 1",
                                  verbatimTextOutput("dat")),
                 conditionalPanel(condition = "input.choice == 2",
                                  verbatimTextOutput("struct")),
                 conditionalPanel(condition = "input.choice == 3",
                                  verbatimTextOutput("summary"))),
        tabPanel("Plot", value = 3, plotOutput("plot")),
        # It need to be used in conditionalPanel of sidebarPanel.
        id = "tabselected"
      )
    )
  )
))
